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
        typedef unsigned long long ull;
        struct Seg
        {
            struct Node
            {
                int mx, mn, xp, np;
                Node() : mx{}, mn{}, xp{-1}, np{-1} {};
                Node(int _, int p) : mx{_}, mn{_}, xp{p}, np{p} {};
                Node operator+(const Node &_) const
                {
                    Node res = *this;
                    if (_.mx > mx)
                        res.xp = _.xp, res.mx = _.mx;
                    if (_.mn < mn)
                        res.np = _.np, res.mn = _.mn;
                    return res;
                }
            };
            vector<Node> Tr;
            int n;
            Seg(int _) : n{_}, Tr(_ + 1 << 2) {}
            void Build(int L, int R, int p, const vector<int> &A)
            {
                if (L == R)
                    Tr[p] = Node(A[L], L);
                else
                {
                    int mid = L + R >> 1;
                    Build(L, mid, p << 1, A);
                    Build(mid + 1, R, p << 1 | 1, A);
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
            void Modify(int x, int y, int L, int R, int p)
            {
                if (L == R)
                {
                    Tr[p].mx = Tr[p].mn = y;
                    return;
                }
                int mid = L + R >> 1;
                if (x <= mid)
                    Modify(x, y, L, mid, p << 1);
                else
                    Modify(x, y, mid + 1, R, p << 1 | 1);
                Tr[p] = Tr[p << 1] + Tr[p << 1 | 1];
            }
        } S(n);
        struct BIT
        {
            vector<ull> C;
            int n;
            BIT(int len) : n(len), C(len + 1) {}
            void Add(int x, ull y)
            {
                while (x <= n)
                    C[x] ^= y, x += x & -x;
            }
            ull Sum(int x)
            {
                ull res = 0;
                while (x)
                    res ^= C[x], x -= x & -x;
                return res;
            }
        } Tr(n);
        vector<int> id(n + 1), re(n + 1);
        for (int i = 1; i <= n; ++i)
            id[i] = rd(), re[id[i]] = i;
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> dep(n + 1), L(n + 1), R(n + 1), fa(n + 1);
        vector<set<pair<int, int>>> has(n + 1);
        int tot = 0;
        auto dfs = [&](auto self, int u, int f) -> void
        {
            L[u] = ++tot;
            dep[u] = dep[f] + 1;
            fa[u] = f;
            has[dep[u]].insert({id[u], u});
            for (int v : E[u])
                if (v ^ f)
                    self(self, v, u);
            R[u] = tot;
        };
        dfs(dfs, 1, 0);
        vector<int> depnow(n + 1);
        for (int i = 1; i <= n; ++i)
            depnow[id[i]] = dep[i];
        S.Build(1, n, 1, depnow);
        mt19937_64 mrand(231654);
        auto RAND = [&]() -> ull
        {
            ull t = mrand();
            t <<= 32;
            t |= mrand();
            return t;
        };
        vector<ull> hash(n + 1), pre(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            pre[i] = hash[i] = RAND();
            pre[i] ^= pre[i - 1];
        }
        auto Modify_range = [&](int x, ull y)
        {
            Tr.Add(L[x], y);
            Tr.Add(R[x] + 1, y);
        };
        for (int i = 1; i <= n; ++i)
            Modify_range(i, hash[id[i]]);
        int q = rd();
        while (q--)
        {
            int op = rd(), x = rd(), y = rd();
            auto Update = [&](int x, int y)
            {
                has[dep[x]].erase({id[x], x});
                has[dep[y]].erase({id[y], y});

                Modify_range(x, hash[id[x]]);
                Modify_range(y, hash[id[y]]);

                S.Modify(id[x], depnow[id[y]], 1, n, 1);
                S.Modify(id[y], depnow[id[x]], 1, n, 1);

                swap(depnow[id[x]], depnow[id[y]]);
                swap(id[x], id[y]);

                Modify_range(x, hash[id[x]]);
                Modify_range(y, hash[id[y]]);

                re[id[x]] = x;
                re[id[y]] = y;

                has[dep[x]].insert({id[x], x});
                has[dep[y]].insert({id[y], y});
            };
            auto check = [&](int l, int r)
            {
                ull now = pre[r] ^ pre[l - 1];
                auto Q = S.query(l, r, 1, n, 1);
                int np = re[Q.np];
                int xp = re[Q.xp];
                if (dep[xp] - dep[np] + 1 > r - l + 1)
                    End("No");

                int need = dep[np] + r - l - dep[xp];
                if (need < 0 || need > n)
                    End("No");

                if (need == 0)
                {
                    auto res = Tr.Sum(L[fa[np]]) ^ Tr.Sum(L[xp]);
                    if (res == now)
                        End("Yes");
                    End("No");
                }
                need += dep[np];
                if (need < 0 || need > n)
                    End("No");
                auto it = has[need].lower_bound({l, -1});
                if (it == has[need].end())
                    End("No");
                int u = it->second;
                if (L[u] >= L[np] && L[u] <= L[xp])
                    ++it;
                if (it == has[need].end())
                    End("No");
                u = it->second;
                auto res = Tr.Sum(L[fa[np]]) ^ Tr.Sum(L[np]) ^ Tr.Sum(L[xp]) ^ Tr.Sum(L[u]);
                if (res == now)
                    End("Yes");
                End("No");
            };
            if (op == 1)
                Update(x, y);
            else
                check(x, y);
        }
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
