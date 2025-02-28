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
        ll k = rd();
        ll l = 1, r = 2e18, ans = 0;
        auto Sqrt = [&](ll x)
        {
            ll l = 1, r = sqrt(x) + 10, ans = 0;
            while (l <= r)
            {
                auto mid = l + r >> 1;
                if (mid * mid <= x)
                    l = mid + 1, ans = mid;
                else
                    r = mid - 1;
            }
            return ans;
        };
        auto check = [&](ll x)
        {
            return x - ll(Sqrt(x)) >= k;
        };
        while (l <= r)
        {
            auto mid = l + r >> 1;
            if (check(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << '\n';
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
