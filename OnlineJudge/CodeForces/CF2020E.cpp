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
        const int mod = 1e9 + 7;
        auto Qpow = [&](int x, int p)
        {
            int res = 1;
            for (; p; p >>= 1, x = 1ll * x * x % mod)
                if (p & 1)
                    res = 1ll * res * x % mod;
            return res;
        };
        int n = rd();
        vector<int> A(n), P(n);
        for (int i = 0; i < n; ++i)
            A[i] = rd();
        for (int i = 0; i < n; ++i)
            P[i] = 1ll * rd() * Qpow(10000, mod - 2) % mod;
        // cout << Qpow(5000, 10000);
        vector<int> ans(1024);
        ans[0] = 1;
        auto Add = [&](auto &x, ll y)
        {
            y %= mod;
            x += y;
            // x %= y;
            if (x >= mod)
                x -= mod;
        };
        for (int i = 0; i < n; ++i)
        {
            auto last = ans;
            ans.assign(1024, 0);
            for (int j = 0; j < 1024; ++j)
            {
                Add(ans[j ^ A[i]], 1ll * last[j] * P[i]);
                Add(ans[j], 1ll * last[j] * (mod + 1 - P[i]));
                // cout << j << ' ' << A[i] << '\n';
            }
        }
        // ll sumP = 0, rx = 0, sumA2 = 0, E_X2 = 0;
        ll sum = 0, total = 0;
        for (int i = 0; i < 1024; ++i)
        {
            // if (ans[i])
            //     cout << i << ' ' << ans[i] << '\n';
            Add(sum, 1ll * ans[i] * i * i);
        }
        cout << sum << '\n';
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
