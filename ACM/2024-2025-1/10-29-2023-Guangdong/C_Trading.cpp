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
        int n = rd();
        vector<pair<int, int>> shop(n + 1);
        for (int i = 1; i <= n; ++i)
            shop[i].first = rd(),
            shop[i].second = rd();

        sort(shop.begin() + 1, shop.end());
        reverse(shop.begin() + 1, shop.end());
        ll sum = 0, ans = 0, total = 0;
        for (int i = 1; i <= n; ++i)
            total += shop[i].second;
        total /= 2;
        for (int i = 1; i <= n; ++i)
        {
            ll cnt = min(total - sum, 0ll + shop[i].second);
            sum += cnt;
            ans += cnt * shop[i].first;
        }
        sum = 0;
        for (int i = n; i >= 1; --i)
        {
            ll cnt = min(total - sum, 0ll + shop[i].second);
            sum += cnt;
            ans -= cnt * shop[i].first;
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
