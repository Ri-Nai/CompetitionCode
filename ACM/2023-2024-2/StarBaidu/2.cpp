#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
        c == '-' && (f = -1), c = getchar();
    while (isdigit(c))
        res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res * f;
}
int main()
{
    const int mod = 998244353;
    int n = rd();
    auto Qpow = [&](int x, int p)
    {
        int res = 1;
        for (; p; p >>= 1, x = 1ll * x * x % mod)
            if (p & 1)
                res = 1ll * res * x % mod;
        return res;
    };
    int tot = 1;
    vector<int> P(n + 1), Pr;
    vector<int> fac(n + 1, 1), inv(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        if (!P[i])
        {
            int t = n / i;
            while (t)
                t /= i, tot = 1ll * tot * i % mod;
            if (1ll * i * i > n)
                continue;
            for (int j = i + i; j <= n; j += i)
                P[j] = 1;
        }
    }
    int sum = 0;
    int ans = 0;
    inv[n] = Qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
    for (int i = 1; i <= n; ++i)
    {
        int now = 1ll * tot * inv[i] % mod * fac[i - 1] % mod;
        ans = (0ll + ans + sum - 1ll * (i - 1) * now % mod + mod) % mod;
        sum = (sum + now) % mod;
    }
    cout << ans << '\n';
}
