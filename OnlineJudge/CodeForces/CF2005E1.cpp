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
        int l = rd(), n = rd(), m = rd();
        vector<int> A(l + 1);
        vector<vector<int>> B(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= l; ++i)
            A[i] = rd();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                B[i][j] = rd();
        vector<vector<int>> last(n + 1, vector<int>(m + 1));
        auto tmp = last;
        for (int pro = l; pro >= 1; --pro)
        {
            auto dp = tmp;
            for (int i = n; i >= 1; --i)
                for (int j = m; j >= 1; --j)
                {
                    auto work = [&](Pr p)
                    {
                        auto [x, y] = p;
                        if (x == -1)
                            return 1;
                        ++x, ++y;
                        if (x > n || y > m)
                            return 0;
                        return last[x][y];
                    };
                    if (i + 1 <= n)
                        dp[i][j] |= dp[i + 1][j];
                    if (j + 1 <= m)
                        dp[i][j] |= dp[i][j + 1];
                    if (B[i][j] == A[pro])
                        dp[i][j] |= work({i, j}) ^ 1;

                }
            last = dp;
        }
        cout << "NT"[last[1][1]] << '\n';
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
