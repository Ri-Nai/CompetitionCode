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
        vector<vector<pair<int, int>>> E(n + 1);
        vector<int> fa(n + 1), from(n + 1), dep(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].emplace_back(v, i);
            E[v].emplace_back(u, i);
        }
        struct DSU
        {
            int n;
            vector<int> fa;
            DSU(int len) : n(len), fa(n + 1) {iota(fa.begin(), fa.end(), 0);}
            int find(int u)
            {
                while (u != fa[u])
                    u = fa[u] = fa[fa[u]];
                return u;
            }
        }S(n);
        auto dfs = [&](auto self, int u, int f) -> void
        {
            fa[u] = f;
            from[u] = f;
            dep[u] = dep[f] + 1;
            for (auto [v, w] : E[u])
            {
                if (v == f)
                    continue;
                self(self, v, u);
            }
        };
        vector<int> ans(n);
        for (int x = n / 2; x >= 1; --x)
        {
            int u = S.find(x);
            for (int y = x + x; y <= n; y += x)
            {
                int v = S.find(v);
                while (u != v)
                {
                    if (dep[u] > dep[v])
                        swap(u, v);
                    ans[from[v]] = x;
                    v = S.fa[v] = S.find(fa[v]);
                }
            }
        }
        dfs(dfs, 1, 0);
        for (int i = 1; i < n; ++i)
            cout << ans[i] << " \n"[i == n - 1];
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
