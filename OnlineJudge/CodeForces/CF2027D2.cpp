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
        int n = rd(), m = rd();
        vector<int> B(m + 1);
        vector<ll> A(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = A[i - 1] + rd();
        for (int i = 1; i <= m; ++i)
            B[i] = rd();
        const ll inf = 1e18;
        const int mod = 1e9 + 7;
        auto Add = [&](int &x, int y)
        {
            if (y < 0)
                y += mod;
            x += y;
            if (x >= mod)
                x -= mod;
            return x;
        };
        vector<pair<ll, int>> dp(n + 1, {inf, 0});
        dp[0] = {0, 1};
        for (int i = 1; i <= m; ++i)
        {
            int now = 0;
            int p = 0, q = 0;
            for (int j = 1; j <= n; ++j)
            {
                while (A[j] - A[p] > B[i])
                    Add(now, mod - dp[p++].second);
                if (q < p)
                    q = p, now = 0;
                while (q < j && dp[q].first == dp[p].first)
                    Add(now, dp[q++].second);
                if (p < j)
                {
                    ll res = dp[p].first + m - i;
                    if (res < dp[j].first)
                        dp[j] = {res, 0};
                    if (res == dp[j].first)
                        Add(dp[j].second, now);
                }
            }
        }
        if (dp[n].first == inf)
            cout << -1 << '\n';
        else
            cout << dp[n].first << ' ' << dp[n].second << '\n';
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
