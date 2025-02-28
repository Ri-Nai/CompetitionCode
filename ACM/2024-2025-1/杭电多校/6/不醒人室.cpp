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
        int n = rd(), m = rd();
        vector<int> L(n + 1), R(n + 1), S(m), T(m);
        for (int i = 1; i <= n; ++i)
            L[i] = rd(), R[i] = rd();
        for (int i = 0; i < m; ++i)
            S[i] = rd(), T[i] = rd();
        int last = -1;
        ll lastans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int p = upper_bound(T.begin(), T.end(), L[i]) - T.begin() - 1;
            ll mx = lastans - L[i] + L[i - 1];
            mx = max(mx, 0ll);
            while (last < p)
            {
                ++last;
                if (S[last] >= R[i - 1])
                    mx = max(mx, 2ll * (T[last] - S[last]));
            }
            if (mx < R[i] - L[i])
                End("No");
            lastans = mx;
        }
        End("Yes");
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
