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
    void solve(int n, int k)
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
        if (k == 0 || n == k)
            End(1);
        End(Qpow(2, k));
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    vector<int> ns;
    vector<int> ks;
    for (int i = 0; i < t; ++i)
        ns.push_back(rd());
    for (int i = 0; i < t; ++i)
        ks.push_back(rd());
    for (int i = 0; i < t; ++i)
        T::solve(ns[i], ks[i]);
    // T::solve();
}
