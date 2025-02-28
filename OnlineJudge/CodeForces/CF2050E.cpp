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
        string a, b, c;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        a = '#' + a;
        b = '!' + b;
        string s;
        cin >> s;
        s = "?" + s;
        int length = n + m;
        vector<vector<int>> dp(length + 1, vector<int>(n + 1, 11451194));
        dp[0][0] = 0;
        for (int i = 1; i <= length; ++i)
            for (int j = 0; j <= n && j <= i; ++j)
            {
                int k = i - j;
                if (k > m)
                    continue;
                // cout << s[i];
                // if (j)
                    // cout << a[j];
                // if (k)
                    // cout << b[k];
                // cout << endl;
                if (j)
                    dp[i][j] = min(dp[i - 1][j - 1] + (s[i] != a[j]), dp[i][j]);
                // cout << i << ' ' << j  << " " << dp[i][j] << endl;
                if (k)
                    dp[i][j] = min(dp[i - 1][j] + (s[i] != b[k]), dp[i][j]);
                // cout << i << ' ' << j  << " " << dp[i][j] << endl;
            }
        cout << dp[length][n] << endl;
        
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
