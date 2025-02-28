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
        const int mod = 998244353;
        vector<ll> ans(n + 2, 1);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; ; ++j)
            {
                if (i * j + 1 > n + 1)
                    break;
                ans[i * j + 1] += ans[i];
                ans[i * j + 1] %= mod;
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i + 1] << " \n"[i == n];
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
