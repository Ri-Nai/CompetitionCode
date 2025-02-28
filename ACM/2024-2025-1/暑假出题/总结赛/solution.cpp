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
        auto ToMin = [&](auto &x, auto y)
        {
            if (x > y)
                x = y;
        };
        const ll inf = 1e18;
        int n = rd(), m = rd();
        vector<vector<ll>> dis(n, vector<ll>(n, inf));
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int u = rd() - 1, v = rd() - 1, w = rd();
            ToMin(dis[u][v], 0ll + w);
            // ToMin(dis[v][u], 0ll + w);
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    ToMin(dis[i][j], dis[i][k] + dis[k][j]);
        int S = 1 << n;
        vector<vector<ll>> dp(n, vector<ll>(S, inf));
        dp[0][1] = 0;
        for (int p = 1; p < S - 1; p += 2)
        {
            for (int i = 0; i < n; ++i)
            {
                if (p >> i & 1 ^ 1)
                    continue;
                for (int j = 0; j < n; ++j)
                {
                    if (p >> j & 1)
                        continue;
                    ToMin(dp[j][p | 1 << j], dp[i][p] + dis[i][j]);
                }
            }
        }
        ll ans = inf;
        for (int i = 0; i < n; ++i)
            ToMin(ans, dp[i][S - 1] + dis[i][0]);
        if (ans == inf)
            ans = -1;
        cout << ans << '\n';
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
