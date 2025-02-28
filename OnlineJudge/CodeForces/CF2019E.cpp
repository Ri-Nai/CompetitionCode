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
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> dep(n + 1);
        vector<int> mxdep(n + 1);
        vector<int> sz(n + 1);
        struct BIT
        {
            vector<int> C;
            int n;
            BIT(int len) : n(len + 1), C(len + 2) {}
            void Add(int x, int y)
            {
                ++x;
                // cout << x << ' ' << y << '\n';
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                int res = 0;
                ++x;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
        } Tr(n);
        dep[0] = -1;
        auto dfs = [&](auto self, int u, int f) -> void
        {
            sz[u] = 1;
            mxdep[u] = dep[u] = dep[f] + 1;
            for (int v : E[u])
                if (v ^ f)
                {
                    self(self, v, u);
                    // cout << v << ' ' << u << '\n';
                    sz[u] += sz[v];
                    mxdep[u] = max(mxdep[u], mxdep[v]);
                }
            // ans[dep[u]] += sz[u] - 1;
            // cout << u << ' ' << mxdep[u] << '\n';
            Tr.Add(dep[u], sz[u] - 1);
            Tr.Add(dep[u] + 1, 1 - sz[u]);
            Tr.Add(mxdep[u] + 1, 1);
            // cout << u << '\n';
        };
        dfs(dfs, 1, 0);
        // cout << "?\n";
        int res = n - 1;
        for (int i = 0; i <= n; ++i)
            res = min(res, Tr.Sum(i));
        assert(Tr.Sum(0) == n - 1);
        cout << res << '\n';
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
