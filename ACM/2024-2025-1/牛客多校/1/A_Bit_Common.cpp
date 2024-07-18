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
    const int N = 5005;
    int C[N][N];
    int pw[N * N];
    void solve()
    {
        int n = rd(), m = rd(), P = rd();
        auto Mod = [&](int x) -> int
        {
            // if (x >= P)
            //     return x - P;
            return x % P;
        };
        pw[0] = 1;
        for (int i = 1; i < N * N; ++i)
            pw[i] = Mod(pw[i - 1] + pw[i - 1]);
        C[0][0] = 1;
        for (int i = 1; i <= max(n, m); ++i)
        {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                C[i][j] = Mod(C[i - 1][j] + C[i - 1][j - 1]);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int now = 0, flag = 1;
            for (int j = 0; j <= m - 1; ++j)
            {
                now = Mod(now + 1ll * flag *  C[m - 1][j] %P * pw[i * (m - 1 - j)] % P);
                flag = P - flag;
            }
            ans = Mod(ans + 1ll * C[n][i] * pw[(m - 1) * (n - i)] % P * now % P);
        }
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
