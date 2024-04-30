#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
ll rd()
{
    ll res = 0;
    int f = 1;
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
        int n = rd();
        ll k = rd();
        vector<ll> A(n + 1);
        ll mx = 0;
        for (int i = 1; i <= n; ++i)
            mx = max(mx, A[i] = rd());
        ll l = 1, r = mx + k, res = 0;
        auto check = [&](ll x)
        {
            ll now = 0;
            for (int i = 1; i <= n; ++i)
                now += max(0ll, x - A[i]);
            return now;
        };
        while (l <= r)
        {
            auto mid = l + r >> 1;
            if (check(mid) <= k)
                l = mid + 1, res = mid;
            else
                r = mid - 1;
        }
        ll t = k - check(res);
        int now = 0;
        int ans = 0;
        auto has = [&] (int x)
        {
            if (A[(x - 1) % n + 1] <= res)
                return 1;
            return 0;
        };
        for (int i = 1, j = 1; i <= n; ++i)
            if (!has(i)) ++ans;
            else if (t > 0) ++ans, --t;
        // cout << t << '\n';
        // cout << "***" << ans << '\n';
        cout << ans + res * n - n + 1 << '\n';
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
