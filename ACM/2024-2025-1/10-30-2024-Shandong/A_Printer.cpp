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
        int n, k;
        scanf("%d%d", &n, &k);
        struct Printer
        {
            int t, l, w;
            void read()
            {
                scanf("%d%d%d", &t, &l, &w);
            }
            ll get(ll limit)
            {
                ll need = 1ll * t * l + w;
                ll already = limit / need;
                ll rest = limit - already * need;
                if (rest > need - w)
                    rest = need - w;
                return already * l + rest / t;
            }
        };
        vector<Printer> P(n + 1);
        for (int i = 1; i <= n; ++i)
            P[i].read();
        ll l = 0, r = 4e18, ans = -1;
        auto check = [&](ll limit)
        {
            ll ans = 0;
            for (int i = 1; i <= n; ++i)
                if ((ans += P[i].get(limit)) >= k)
                    return 1;
            return 0;
        };
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (check(mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << endl;
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
