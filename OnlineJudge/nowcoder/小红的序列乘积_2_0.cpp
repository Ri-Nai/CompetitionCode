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
        //end with 6
        //
        int n = rd();
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            A[i] = rd() % 10;
        }
        vector<array<int, 10>> dp(n + 1, array<int, 10>{});
        vector<array<int, 10>> nums(n + 1, array<int, 10>{});
        nums[0][1] = 1;
        // dp[i][p] = dp[i - 1][j];
        // dp[i][j]
        const int mod = 1e9 + 7;
        auto Add = [&](int &x, int y)
        {
            x += y;
            if (x >= mod)
                x -= mod;
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= 9; ++j)
            {
                int p = j * A[i] % 10;
                Add(nums[i][p], nums[i - 1][j]);
                // if (p == 6)
                    // cout << dp[i - 1][j] << ' ' << nums[i - 1][j] << '\n';
                Add(dp[i][p], dp[i - 1][j]);
                if (p == 6)
                    Add(dp[i][p], nums[i - 1][j]);

            }
            for (int j = 0; j <= 9; ++j)
                Add(ans, dp[i][j]);
            for (int j = 0; j <= 9; ++j)
                Add(dp[i][j], dp[i - 1][j]),
                Add(nums[i][j], nums[i - 1][j]);
        }
        // cout << dp[n][6] << '\n';
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
