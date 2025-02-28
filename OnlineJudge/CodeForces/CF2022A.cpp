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
        int n = rd(), r = rd();
        vector<int> A(n);
        // int sum = 0;
        int ans = 0, cnt = 0;;
        for (int i = 0; i < n; ++i)
        {
            A[i] = rd();
            r -= A[i] / 2;
            ans += A[i] - (A[i] & 1);
            A[i] &= 1;
            if (A[i])
                ++cnt;
        }
        // t + (cnt - t) / 2 = r
        // cout << 2 * cnt - r << '\n';
        for (int i = cnt; i >= 0; --i)
        {
            if (i + (cnt - i + 1) / 2 <= r)
                End(ans + i);
        }
        // cout << ans << '\n';
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
