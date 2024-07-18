#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
        c == '-' && (f = -1), c = getchar();
    while (isdigit(c))
        res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res * f;
}
const int mod = 998244353;
void Add(int &x, int y)
{
    x += y;
    if (x > mod)
        x -= mod;
}
int main()
{
    int n = rd(), k = rd();
    auto Qpow = [&](int x, int p)
    {
        int res = 1;
        for (; p; p >>= 1, x = 1ll * x * x % mod)
            if (p & 1)
                res = 1ll * res * x % mod;
        return res;
    };
    string s;
    cin >> s;
    vector<int> A(n + 1);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(4)));
    for (int i = 1; i <= n; ++i)
        A[i] = s[i - 1] - 48;
    dp[0][0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cur = i & 1;
        dp[cur].assign(k + 1, vector<int>(4));
        for (int j = 0; j <= min(k, n - 1); ++j)
        {
            for (int p = 0; p < 4; ++p)
            {
                int now0 = p << 1 | A[i];
                int now1 = p << 1 | A[i] ^ 1;
                if (j + 1 <= k)
                    if (i < 3 || now1 != 6)
                        Add(dp[cur][j + 1][now1 & 3], dp[cur ^ 1][j][p]);
                if (i < 3 || now0 != 6)
                    Add(dp[cur][j][now0 & 3], dp[cur ^ 1][j][p]);
            }
        }
    }
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < 4; ++j)
            Add(ans, dp[n & 1][i][j]);
    cout << ans << '\n';
}
