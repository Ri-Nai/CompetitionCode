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
        // vector<int> a(n + 1);
        vector<vector<int>> edge(n + 1);
        vector<int> in(n + 1, -2);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
            ++in[u], ++in[v];
        }
        vector<int> dp(n + 1);
        int ans = 0;
        auto dfs = [&](auto &&self, int u, int f) -> void
        {
            dp[u] = in[u];
            for (int v : edge[u])
            {
                if (v == f)
                    continue;
                self(self, v, u);
                ans = max(ans, dp[u] + dp[v] + 2);
                dp[u] = max(dp[u], dp[v] + in[u]);
            }
            ans = max(ans, dp[u] + 2);
        };
        dfs(dfs, 1, 0);
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
