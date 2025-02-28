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
        vector<int> A(n + 1), B(n + 1);
        ll sum = 0;
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), sum += B[i] = rd();
        // cout << sum << '\n';
        if (sum % 3 != 0)
            End(-1);
        int m = sum / 3;
        const int inf = 1e9;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, inf));
        dp[0][0] = 0;
        auto last = dp;
        for (int i = 1; i <= n; ++i)
        {
            dp.assign(m + 1, vector<int>(m + 1, inf));
            auto Min = [&](auto &x, auto y)
            {
                if (y < x)
                    x = y;
                return x;
            };
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= m; ++k)
                {
                    if (j + B[i] <= m)
                    {
                        // if (j == 0 && k == 0)
                        //     cout << "AAA " << last[j][k] << endl;
                        Min(dp[j + B[i]][k], last[j][k] + (A[i] != 1));
                    }
                    if (k + B[i] <= m)
                        Min(dp[j][k + B[i]], last[j][k] + (A[i] != 2));
                    Min(dp[j][k], last[j][k] + (A[i] != 3));
                }
            // for (int j = 0; j <= m; ++j, cout << endl)
            //     for (int k = 0; k <= m; ++k)
            //         cout << dp[j][k] << ' ';
            last = dp;

        }
        sum /= 3;
        if (dp[m][m] == inf)
            puts("-1");
        else cout << dp[m][m] << '\n';
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
