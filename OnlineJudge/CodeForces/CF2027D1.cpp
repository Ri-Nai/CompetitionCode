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
        vector<int> B(m + 1);
        vector<ll> A(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = A[i - 1] + rd();
        for (int i = 1; i <= m; ++i)
            B[i] = rd();
        const ll inf = 1e18;
        auto dp = vector(n + 1, vector<ll>(m + 1, inf));
        fill(dp[0].begin(), dp[0].end(), 0);
        vector<int> ptr(m + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                int &q = ptr[j];
                while (A[i] - A[q] > B[j])
                    ++q;
                dp[i][j] = min(dp[i][j - 1], dp[q][j] + m - j);
            }
        }
        if (dp[n][m] == inf)
            dp[n][m] = -1;
        cout << dp[n][m] << endl;
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
