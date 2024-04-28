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
const int N = 3e5 + 5, mod = 1e9 + 7;
int fac[N], inv[N], pw[N];
int Qpow(int x, int p)
{
    int res = 1;
    for (; p; p >>= 1, x = 1ll * x * x % mod)
        if (p & 1)
            res = 1ll * x * res % mod;
    return res;
}
int C(int n, int m)
{
    return 1ll * fac[n] * inv[n - m] % mod * inv[m] % mod;
}
namespace T
{
    void solve()
    {
        int n = rd(), k = rd();
        while (k--)
        {
            int x = rd(), y = rd();
            if (x == y)
                --n;
            else
                n -= 2;
        }
        int ans = 1, now = 1;
        for (int i = 2; i <= n; i += 2)
        {
            now = 1ll * now * (i - 1) % mod;
            int tmp = 1ll * pw[i >> 1] * now % mod * C(n, i) % mod;
            ans = (ans + tmp) % mod;
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    fac[0] = 1, pw[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = 1ll * i * fac[i - 1] % mod,
        pw[i] = 2ll * pw[i - 1] % mod;
    inv[N - 1] = Qpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
