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
        const int mod = 998244353;
        vector<int> A(n + 1);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        auto Add = [&](int &x, int y)
        {
            x += y;
            if (x >= mod)
                x -= mod;
            if (x < 0)
                x += mod;
        };
        dp[0][0][0] = 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                for (int k = 0; k <= n; ++k)
                {
                    if (!i || !j || !k)
                        dp[i][j][k] = 1;
                    else
                    {
                        if (A[i] == A[j] && A[j] == A[k])
                            dp[i][j][k] = dp[i - 1][j - 1][k - 1];
                        Add(dp[i][j][k], dp[i - 1][j][k]);
                        Add(dp[i][j][k], dp[i][j - 1][k]);
                        Add(dp[i][j][k], dp[i][j][k - 1]);
                        Add(dp[i][j][k], -dp[i - 1][j - 1][k]);
                        Add(dp[i][j][k], -dp[i][j - 1][k - 1]);
                        Add(dp[i][j][k], -dp[i - 1][j][k - 1]);
                        Add(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
                    }
                }
        cout << dp[n][n][n] - 1 << '\n';
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
