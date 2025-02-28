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
        int n = rd();
        vector<int> val(n + 1), to(n + 1);
        for (int i = 1; i <= n; ++i)
            val[i] = rd();
        vector<vector<int>> from(n + 1);
        for (int i = 1; i <= n; ++i)
            from[to[i] = rd()].push_back(i);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + val[i];
        struct Seg
        {
            struct Node
            {
                ll mx, mn;
                Node() : mx{}, mn{} {};
                Node(ll _) : mx{_}, mn{_} {};
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
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void build(int L, int R, int p)
            {
                if (L == R)
                {
                    Tr[p] = Node(L == 1 ? 0 : 1e18);
                }
                else
                {
                    int mid = L + R >> 1;
                    build(L, mid, p << 1);
                    build(mid + 1, R, p << 1 | 1);
                    Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
                }
            }
            Node query(int l, int r, int L, int R, int p)
            {
                if (l == L && R == r)
                    return Tr[p];
                int mid = L + R >> 1;
                if (r <= mid)
                    return query(l, r, L, mid, p << 1);
                else if (l > mid)
                    return query(l, r, mid + 1, R, p << 1 | 1);
                return query(l, mid, L, mid, p << 1) + query(mid + 1, r, mid + 1, R, p << 1 | 1);
            }
            void modify(int x, ll y, int L, int R, int p)
            {
                if (L == R)
                {
                    if (y < Tr[p].mn)
                        Tr[p].mx = Tr[p].mn = y;
                    return;
                }
                int mid = L + R >> 1;
                if (x <= mid)
                    modify(x, y, L, mid, p << 1);
                else
                    modify(x, y, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(n);
        S.build(1, n, 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll mn = 1e18;
            if (i == 1)
                mn = 0;
            for (auto v : from[i])
            {
                if (v >= i)
                    continue;
                mn = min(mn, S.query(v, i - 1, 1, n, 1).mn + val[v]);
            }
            S.modify(i, mn, 1, n, 1);
            ans = max(ans, sum[i] - mn);
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
