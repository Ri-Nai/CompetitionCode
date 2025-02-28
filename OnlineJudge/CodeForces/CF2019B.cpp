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
        int n = rd(), m = rd();
        vector<int> X(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd();
        map<ll, ll> ans;
        for (int i = 1; i < n; ++i)
            ans[1ll * i * (n - i)] += X[i + 1] - X[i] - 1;
        for (int i = 1; i <= n; ++i)
            ++ans[1ll * i * (n - i + 1) - 1];
        while (m--)
            cout << ans[rd()] << " \n"[m == 0];
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
