#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pr;
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
        int n = rd(), m = rd();
        vector<Pr> arr;
        for (int i = 0; i < n; ++i)
        {
            int u = rd(), v = rd();
            arr.emplace_back(u, v);
        }
        if (n == 1)
        {
            cout << arr[0].second << '\n';
            return;
        }
        auto diff = [&](const Pr &a)
        {
            return a.second - a.first;
        };
        auto cmp = [&](const Pr &a, const Pr &b) -> bool
        {
            return diff(a) > diff(b);
        };
        int max_lonely = min(n, m - n);
        sort(arr.begin(), arr.end(), cmp);
        ll ans = 0, sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i].first;
        ans = max(ans, sum);
        for (int i = 0; i < max_lonely; ++i)
        {
            sum += diff(arr[i]);
            if (i == n - 2)
            {
                max_lonely = n;
                continue;
            }
            ans = max(ans, sum);
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
