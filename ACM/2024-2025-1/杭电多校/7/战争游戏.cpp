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
        int n = rd(), s = rd(), r1 = rd(), r2 = rd();
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> dep(n + 1);
        int rt = 1;
        auto dfs = [&](auto self, int u, int f) -> void
        {
            for (int v : E[u])
            {
                if (v == f)
                    continue;
                dep[v] = dep[u] + 1;
                if (dep[v] > dep[rt])
                    rt = v;
                self(self, v, u);
            }
        };
        dfs(dfs, 1, 0);
        dep[rt] = 0;
        dfs(dfs, rt, 0);
        int mn = min(r2, dep[rt]);
        if (2 * r1 >= mn)
            End("Kangaroo_Splay");
        else End("General_Kangaroo");
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
