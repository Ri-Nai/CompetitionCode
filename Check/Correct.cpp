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
        vector<ll> A(n + 1), B(n + 1);
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), B[i] = rd();
        for (int i = 1; i <= n; ++i)
            dp[1][i] = A[i] + B[i];
        for (int i = 2; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    if (j ^ k)
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + A[j] + i * B[j]);
        ll res = 0;
        for (int i = 1; i <= n; ++i)
            res = max(res, dp[m][i]);
        cout << res << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
