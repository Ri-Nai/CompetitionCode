#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    const int mod = 998244353;
    auto Qpow = [](int x, int p, int mod)
    {
        int res = 1;
        for (; p; p >>= 1, x = 1ll * x * x % mod)
            if (p & 1)
                res = 1ll * res * x % mod;
        return res;
    };
    cout << Qpow(a, Qpow(b, c, mod - 1), mod) << endl;
}
// 2 ** 2 ** 3 % 5 
// 2 ** 8 % 5
// 2
