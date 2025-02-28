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
        vector<vector<int>> E(n + 1);
        vector<vector<int>> fa(n + 1, vector<int>(15)), son(n + 1, vector<int>(15));
        vector<int> sz(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        auto dfs = [&](auto self, int u, int f) -> void
        {
            fa[u][0] = f;
            sz[u] = 1;
            for (int v : E[u])
            {
                if (v == f)
                    continue;
                self(self, v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[son[u][0]])
                    son[u][0] = v;
            }
            if (!son[u][0])
                son[u][0] = u;
        };
        dfs(dfs, 1, 1);
        for (int i = 1; i < 15; ++i)
            for (int j = 1; j <= n; ++j)
                fa[j][i] = fa[fa[j][i - 1]][i - 1],
                son[j][i] = son[son[j][i - 1]][i - 1];
        auto quest = [&](int x)
        {
            cout << "? " << x << endl;
            int y;
            cin >> y;
            return y;
        };
        auto work = [&](auto self, int u) -> void
        {
            while (1)
            {
                u = fa[u][0];
            }
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
