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
        int k = rd();
        vector<ll> dp(4 * n + 1, 1e18);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a = rd(), b = rd(), c = rd(), d = rd();
            for (int j = min(4 * i, k); j >= 0; --j)
            {
                if (j - 1 >= 0)
                    dp[j] = min(dp[j], dp[j - 1] + a);
                if (j - 2 >= 0)
                    dp[j] = min(dp[j], dp[j - 2] + b);
                if (j - 3 >= 0)
                    dp[j] = min(dp[j], dp[j - 3] + c);
                if (j - 4 >= 0)
                    dp[j] = min(dp[j], dp[j - 4] + d);
            }
        }
        cout << dp[k] << '\n';
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
