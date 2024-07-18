#include <stdio.h>
#include <ctype.h>
#include <algorithm>
typedef long long ll;
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
const int N = 5005;
int C[N][N], f[N][N];
int pw[N * N];
int n, m, P;
int Qpow(int x, int p)
{
    int res = 1;
    for (; p; p >>= 1, x = 1ll * x * x % P)
        if (p & 1)
            res = 1ll * res * x % P;
    return res;
}
inline int Mod(int x)
{
    if (x < 0)
        x += P;
    if (x >= P)
        x -= P;
    return x;
}
void solve()
{
    n = rd(), m = rd(), P = rd();
    pw[0] = 1;
    for (int i = 1; i <= std::max(m, n); ++i)
        pw[i] = Mod(pw[i - 1] + pw[i - 1]);
    C[0][0] = 1;
    for (int i = 1; i <= std::max(n, m); ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = Mod(C[i - 1][j] + C[i - 1][j - 1]);
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i][i] = 1ll * f[i - 1][i - 1] * i % P;
        for (int j = i + 1; j <= m; ++j)
            f[i][j] = Mod(f[i][j - 1] + f[i - 1][j - 1]) * 1ll * i % P;
        // for (int j = i; j <= m; ++j)
            // printf("%d%c", f[i][j], " \n"[j ==m]);
    }
    int ans = 0;

    for (int i = 2; i <= n; ++i)
    {
        int now = 0, flag = 1;
        int ppw = 1;
        for (int j = m - 1; j >= i; --j)
        {
            now = Mod(now + 1ll * ppw * C[m - 1][j] % P * f[i][j] % P);
            ppw = 1ll * ppw * Mod(pw[i] - i - 1) % P;
        }
        now = Mod(Qpow(Mod(pw[i] - 1), m - 1) - now);
        ans = Mod(ans + 1ll * C[n][i] * Qpow(pw[m - 1], (n - i)) % P * now % P);
    }
    printf("%d\n", ans);
}
int main()
{
    solve();
}
