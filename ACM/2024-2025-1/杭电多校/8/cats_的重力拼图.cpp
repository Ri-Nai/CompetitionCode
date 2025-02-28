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
        int n = rd(), m = rd(), a = rd(), b = rd();
        ll res = n - 1 + m - 1 + n - 1 + m - 1;
        if (n == 1 && m == 1)
            End("1");
        if (n == 1)
            End(m);
        if (m == 1)
            End(n);
        int add = 0;
        if (a != 1 && a != n)
            add = max(add, m - 2);
        if (b != 1 && b != m)
            add = max(add, n - 2);
        // cout << res << ' ' << add << '\n';
        // cout << res << ' ' << add << '\n';
        cout << res + add << '\n';
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
