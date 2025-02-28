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
        vector<vector<int>>A(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                A[i][j] = rd();
        int target = rd();
        vector<vector<int>> dp(n + 1, vector<int>(5005));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int k = i * 50; k >= 0; --k)
                for (int j = 1; j <= m; ++j)
                    if (k - A[i][j] >= 0)
                        dp[i][k] |= dp[i - 1][k - A[i][j]];
        }
        int ans = 50000;
        for (int i = 1; i <= 5000; ++i)
            if (dp[n][i])
                ans = min(abs(i - target), ans);
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
