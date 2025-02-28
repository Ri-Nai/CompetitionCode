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
    char s[200005];
    void solve()
    {
        int n = rd(), Q = rd();
        vector<int> A(n + 1), op(n + 2, -1), pos(n + 1), val(n + 1);
        for (int i = 1; i <= n; ++i)
            pos[A[i] = rd()] = i;
        scanf("%s", s + 1);
        for (int i = 1; i <= n; ++i)
            op[i] = s[i] == 'R';
        vector<pair<int, int>> seg;

        for (int i = n; i >= 1; --i)
            if (pos[i] < i)
                seg.emplace_back(pos[i], i - 1);

        auto tmp = seg;
        sort(tmp.begin(), tmp.end());
        seg.clear();

        for (auto p : tmp)
            if (seg.empty() || p.second > seg.back().second)
                seg.push_back(p);
        int m = seg.size();

        struct Seg
        {
            struct Node
            {
                int val, lz;
                Node() : val{}, lz{} {};
                Node operator+(const Node &_) const
                {
                    Node res;
                    res.val = _.val + val;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void change(int p, int x)
            {
                Tr[p].val += x;
                Tr[p].lz += x;
            }
            void pushDown(int p)
            {
                change(p << 1, Tr[p].lz);
                change(p << 1 | 1, Tr[p].lz);
                Tr[p].lz = 0;
            }

            int query(int l, int r, int L, int R, int p)
            {
                if (l == L && R == r)
                    return Tr[p].val;
                pushDown(p);
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
            void update(int l, int r, int x, int L, int R, int p)
            {
                if (l > r)
                    return;
                if (L == l and r == R)
                    return change(p, x);
                pushDown(p);
                int mid = L + R >> 1;
                if (r <= mid)
                    update(l, r, x, L, mid, p << 1);
                else if (l > mid)
                    update(l, r, x, mid + 1, R, p << 1 | 1);
                else
                    update(l, mid, x, L, mid, p << 1), update(mid + 1, r, x, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(m + 10);

        vector<int> L(n + 1, m + 1), R(n + 1, m + 1);
        auto check_in = [&](auto P, int x)
        {
            auto [l, r] = P;
            return x >= l && x <= r;
        };

        int l = 0, r = 0;
        for (int i = seg.empty() ? n : seg[0].first; i < n; ++i)
        {
            while (l < m && !check_in(seg[l], i))
                ++l;
            if (r < l)
                r = l;
            while (r + 1 < m && check_in(seg[r + 1], i))
                ++r;
            L[i] = l + 1;
            R[i] = r + 1;
        }

        auto Modify = [&](int i)
        {
            if (seg.empty())
                return;
            if (i == n || i == 0)
                return;
            int nxt = op[i] == 0 && op[i + 1] == 1;
            S.update(L[i], R[i], nxt - val[i], 1, m + 1, 1);
            val[i] = nxt;
        };

        for (int i = 1; i < n; ++i)
            Modify(i);

        auto work = [&]()
        {
            if (seg.empty())
                return true;
            int x = rd();
            op[x] ^= 1;
            Modify(x - 1);
            Modify(x);
            return S.query(1, m, 1, m + 1, 1) == 0;
        };
        for (int i = 1; i <= Q; ++i)
            if (work())
                puts("YES");
            else
                puts("NO");
        // delete s;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
