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
        vector<int> A(n + 1), B(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd();
        for (int i = 1; i <= n; ++i)
            B[i] = rd();
        ll cnt1 = 0, cnt2 = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (A[i] == B[i])
                ++cnt1;
        for (int i = 1; i <= n; ++i)
            if (A[i] > B[i])
                ++ans;
        ans += cnt1 + 1 >> 1;
        cout << ans << '\n';

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
