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
    void solve()
    {
        ll P = rd(), m = rd();
        // if (P == 2)
        //     cout << m + 1 << '\n';
        // else
        {
            // kP + 1 <= m
            ll ans = m / P;
            ll idx = ans - 1;
            auto check = [&](__int128 idx, ll limit)
            {
                auto now = idx * P + 1;
                if ((now ^ P - 1) <= limit)
                    return 1;
                return 0;
            };
            ans += check(idx + 1, m);
            ans += check(idx + 2, m);
            cout << ans << '\n';
        }
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
/*
g ^ (P - 1) === 1
P
1 ^ (P - 1)
(P + 1) ^ (P - 1)  6 ^ 8 = 14
(2P + 1) ^ (P - 1) 6 ^ 15 = 9
kP + 1
*/
