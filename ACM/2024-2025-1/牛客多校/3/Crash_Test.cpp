#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
ll rd()
{
    ll res = 0, f = 1;
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
    ll gcd(ll a, ll b)
    {
        return b ? gcd(b, a % b) : a;
    }
    void solve()
    {
        int n = rd();
        ll D = rd();
        vector<ll> h(n + 1);
        for (int i = 1; i <= n; ++i)
            h[i] = rd();
        sort(h.begin() + 1, h.end());
        auto it = unique(h.begin() + 1, h.end());
        n = it - h.begin() - 1;
        h.erase(it, h.end());
        ll g = h[1];
        for (int i = 2; i <= n; ++i)
            g = gcd(h[i] % h[i - 1], g);
        cout << D % g << '\n';
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
/*
hj - (hi - now)
now + hi - hj

{if (hi >= hj - now)}
now - (hi - hj) >= 0
*/

