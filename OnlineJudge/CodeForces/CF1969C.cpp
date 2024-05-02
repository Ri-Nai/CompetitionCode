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
        int n = rd(), k = rd();
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e18));
        ll ans = 1e18;
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                int mn = A[i];
                for (int p = 0; j + p <= k && i - p >= 1; ++p)
                {
                    // cout << i << ' ' << j << ' ' << p << ' ' << dp[i][j + p] << ' ' << dp[i - p - 1][j] << '\n';
                    mn = min(mn, A[i - p]);
                    dp[i][j + p] = min(dp[i][j + p], dp[i - p - 1][j] + 1ll * (p + 1) * A[i]);
                    dp[i][j + p] = min(dp[i][j + p], dp[i - p - 1][j] + 1ll * (p + 1) * mn);
                    // cout << i << ' ' << j << ' ' << p << ' ' << dp[i][j + p] << ' ' << dp[i - p - 1][j] << '\n';
                }
            }

        }
        for (int i = 0; i <= k; ++i)
        {
            // cout << dp[n][i] << ' ';
            ans = min(ans, dp[n][i]);
        }
        // cout << '\n';
        cout << ans << '\n';
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
