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
        vector<vector<int>> dp(n + 1, vector<int>(10, -1e9));
        auto check = [&](char x, char y, char z) -> int
        {
            return (x == 'A') + (y == 'A') + (z == 'A') >= 2;
        };
        auto Max = [&](int &x, int y)
        {
            if (y > x)
                x = y;
        };
        auto DP = [&](int x, int y) -> int &
        {
            if (x < 0)
                return dp[0][0];
            return dp[x][y + 3];
        };
        // -3 1 0 1 3
        DP(0, 0) = 0;
        // for (int i = 1; i <= n;
        vector<string> S(2);
        for (int i : {0, 1})
        {
            string s = "*", t;
            cin >> t;
            s += t;
            S[i] = s;
        }
        for (int i = 1; i <= n; ++i)
        {
            Max(DP(i, 0), DP(i - 3, 0) + check(S[0][i - 2], S[0][i - 1], S[0][i]) + check(S[1][i - 2], S[1][i - 1], S[1][i]));

            Max(DP(i, -1), DP(i - 2, 0) + check(S[0][i - 1], S[1][i - 1], S[1][i]));
            Max(DP(i, 1), DP(i - 2, 0) + check(S[0][i - 1], S[1][i - 1], S[0][i]));

            Max(DP(i, 0), DP(i - 1, -1) + check(S[0][i], S[1][i], S[0][i - 1]));
            Max(DP(i, 0), DP(i - 1, 1) + check(S[0][i], S[1][i], S[1][i - 1]));

            for (int j : {1, 2})
                Max(DP(i, j), DP(i - j, j - 3) + check(S[0][i], S[0][i - 1], S[0][i - 2]));
            for (int j : {-1, -2})
                Max(DP(i, j), DP(i + j, j + 3) + check(S[1][i], S[1][i - 1], S[1][i - 2]));
        }
        cout << DP(n, 0) << '\n';
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
