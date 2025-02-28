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
        vector<int> C(n + 1), W(n + 1);
        for (int i = 1; i <= n; ++i)
            C[i] = rd();
        for (int i = 1; i <= n; ++i)
            W[i] = rd();
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> sz(n + 1, 1), son(n + 1), fa(n + 1);
        auto dfs = [&](auto self, int u, int f) -> void
        {
            fa[u] = f;
            for (int v : E[u])
                if (v != f)
                {
                    self(self, v, u);
                    sz[u] += sz[v];
                    if (sz[son[u]] < sz[v])
                        son[u] = v;
                }
        };
        dfs(dfs, 1, 0);
        vector<ll> sum(n + 1);
        auto dfs_ = [&](auto self, int u, bool is) -> void
        {
            for (int v : E[u])
                if (v != fa[u] && v != son[u])
                    self(self, v, 0), sum[u] += sum[v];
            self(self, son[u], 1);
            sum[u] += sum[son[u]];
        };

    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
