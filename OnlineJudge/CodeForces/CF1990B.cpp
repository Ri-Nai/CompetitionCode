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
        int n = rd(), x = rd(), y = rd();
        vector <int> ans(n + 1);
        for (int i = y; i <= x; ++i)
            ans[i] = 1;
        for (int i = y - 1; i >= 1; --i)
            ans[i] = ((y - i) & 1) ? -1 : 1;
        for (int i = x + 1; i <= n; ++i)
            ans[i] = ((x - i) & 1) ? -1 : 1;
        if (y != 1)
            ans[1] = -1;
        if (x != n)
            ans[n] = -1;
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << " \n"[i == n];

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
