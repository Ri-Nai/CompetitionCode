#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
        (c = getchar()) == '-' && (f = -1);
    while (!isdigit(c));
    while (isdigit(c))
        res = (c ^ 48) + (res << 1) + (res << 3), c = getchar();
    return res * f;
}
namespace T
{
    void solve()
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        struct Seg
        {
            struct Node
            {
                int mx, mn;
                Node() : mx{}, mn{} {};
                Node(int _) : mx{_}, mn{_} {};
                Node operator+(const Node &_) const
                {
                    Node res = *this;
                    if (_.mx > mx)
                        res.mx = _.mx;
                    if (_.mn < mn)
                        res.mn = _.mn;
                    return res;
                }
            };
            vector<Node> tr;
            int n;
            Seg(int _) : n{_}, tr(_ + 1 << 2) {}
            void build(int L, int R, int p, const vector<int> &a)
            {
                if (L == R)
                    tr[p] = Node(a[L]);
                else
                {
                    int mid = L + R >> 1;
                    build(L, mid, p << 1, a);
                    build(mid + 1, R, p << 1 | 1, a);
                    tr[p] = tr[p << 1] + tr[p << 1 | 1];
                }
            }
            Node query(int l, int r, int L, int R, int p)
            {
                if (l == L && R == r)
                    return tr[p];
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
        } st(n);
        st.build(1, n, 1, a);
        struct BIT
        {
            vector<int> c;
            int n;
            BIT(int len) : n(len + 1), c(len + 2) {}
            void add(int x, int y)
            {
                ++x;
                while (x <= n)
                    c[x] += y, x += x & -x;
            }
            int sum(int x)
            {
                int res = 0;
                ++x;
                while (x)
                    res += c[x], x -= x & -x;
                return res;
            }
        } bt(n);
        int l = 1;
        int ans = 0;
        bt.add(a[1], 1);
        auto check = [&](int id)
        {
            auto now = st.query(l, id - 1, 1, n, 1);
            if (now.mx < a[id] || now.mn > a[id])
                return true;
            int lower = a[id - 1];
            int upper = a[id];
            if (lower > upper)
                swap(lower, upper);
            bt.add(a[id], 1);
            int cnt = bt.sum(upper) - bt.sum(lower - 1);
            bt.add(a[id], -1);
            int r = id - cnt;
            auto res = st.query(r + 1, id, 1, n, 1);
            return res.mx <= upper && res.mn >= lower;
        };
        for (int i = 2; i <= n; ++i)
        {
            if (check(i))
            {
                // cout << i << " ";
                ++ans;
            }
            else
                while (l < i)
                    bt.add(a[l++], -1);
            bt.add(a[i], 1);
        }
        cout << ans << endl;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
