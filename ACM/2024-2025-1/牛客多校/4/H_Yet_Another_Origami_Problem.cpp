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
    const int N = 5e5 + 5;
    ll A[N];
    ll gcd(ll a, ll b)
    {
        return b ? gcd(b, a % b) : a;
    }
    void solve()
    {
        int n = rd();
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        sort(A + 1, A + n + 1);
        n = unique(A + 1, A + n + 1) - A - 1;
        if (n == 1)
        {
            cout << 0 << '\n';
            return;
        }
        ll ans = A[2] - A[1];
        for (int i = 3; i <= n; ++i)
            ans = gcd(ans, A[i] - A[i - 1]);
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
/*
2 4 5 3

6 4 3 5

1 2 100
-196 2 3
1 0 -98
1 0

2ap - ai

2ap - ai // ap

*/
