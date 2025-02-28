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
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        vector<ll> dp(n + 1, 1e18);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            if (A[i] == 0)
                dp[i] = min(dp[i], dp[i - 1]);
            if (i >= 2)
                dp[i] = min(dp[i], dp[i - 2] + (max(A[i], A[i - 1]) + 1) / 2);
            if (i >= 3)
                dp[i] = min(dp[i], dp[i - 3] + (max(A[i], A[i - 1]) + 1) / 2 + (max(A[i - 1], A[i - 2]) + 1) / 2);
            if (i >= 4 && A[i - 3] <= 2 && A[i - 2] <= 4 && A[i - 1] <= 4 && A[i] <= 2)
                dp[i] = min(dp[i], dp[i - 4] + 3);

        }
        cout << dp[n] << '\n';
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
/*
如果是1则
1 0 1 0
0 1 1 0
0 0 1 0
1 1 0 0
左边为1是有4中排列
1 * 8 + 4
12 种
4
*/
