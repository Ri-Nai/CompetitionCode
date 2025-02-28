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
    typedef unsigned long long ull;
    mt19937_64 mrand(231654);
    ull RAND()
    {
        ull t = mrand();
        t <<= 32;
        t |= mrand();
        return t;
    }
    void solve()
    {
        int n = rd(), q = rd();
        vector<int> A(n + 1);
        vector<vector<int>> E(n + 1);
        for (int i = 2; i <= n; ++i)
        {
            A[i] = rd();
            E[A[i]].push_back(i);
        }
        vector<ull> Hash(n + 1), res(n + 1);
        vector<int> sz(n + 1, 1);
        auto dfs = [&](auto self, int u) -> void
        {
            res[u] = Hash[u] = RAND();
            for (auto v : E[u])
            {
                self(self, v);
                res[u] ^= res[v];
                sz[u] += sz[v];
            }
        };
        dfs(dfs, 1);
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
        vector<int> P(n + 1), Q(n + 1);
        vector<int> mark(n + 1);
        for (int i = 1; i <= n; ++i)
            P[i] = rd(), Q[P[i]] = i;
        int now = 0;
        for (int i = 1; i <= n; ++i)
            Tr.Add(i, Hash[P[i]]);
        auto Modify = [&](int u, int p)
        {
            int is = Q[u]; //这个点应该在哪;
            if (is + sz[u] - 1 <= n)
            {
                ull t = Tr.Sum(is + sz[u] - 1) ^ Tr.Sum(is - 1);
                if (t == res[u])
                {
                    if (p == -1 && mark[u] == 1)
                        mark[u] = 0, --now;
                    else if (p == 1 && !mark[u])
                        mark[u] = 1, ++now;
                }
            }
        };
        for (int i = 1; i <= n; ++i)
            Modify(i, 1);
        for (int i = 1; i <= q; ++i)
        {
            int x = rd(), y = rd();
            auto jumping = [&](int u, int p)
            {
                while (u)
                {
                    Modify(u, p);
                    u = A[u];
                }
            };
            jumping(P[x], -1);
            jumping(P[y], -1);
            Tr.Add(x, Hash[P[x]]);
            Tr.Add(y, Hash[P[y]]);
            Q[P[x]] = y;
            Q[P[y]] = x;
            swap(P[x], P[y]);
            Tr.Add(x, Hash[P[x]]);
            Tr.Add(y, Hash[P[y]]);
            jumping(P[x], 1);
            jumping(P[y], 1);
            if (now == n)
                cout << "YES\n";
            else cout << "NO\n";

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
/*
dfs_order = []

function dfs(v):
    append v to the back of dfs_order
    pick an arbitrary permutation s of children of v
    for child in s:
        dfs(child)
dfs(1)
*/
