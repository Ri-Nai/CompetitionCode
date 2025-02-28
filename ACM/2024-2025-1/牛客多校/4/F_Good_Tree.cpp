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
        ll x = rd();
        ll ans = 1;
        while (x)
        {
            ll l = 1, r = sqrt(2 * x), y = 1;
            while (l <= r)
            {
                ll mid = l + r >> 1;
                if ((mid * (mid + 1) >> 1) <= x)
                    l = mid + 1, y = mid;
                else r = mid - 1;
            }
            ans += y;
            x -= y * (y + 1) >> 1;
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
