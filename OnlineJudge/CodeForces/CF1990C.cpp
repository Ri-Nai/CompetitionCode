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
        vector<int> A(n + 1);
        vector<int> cnt(n + 1);
        ll sum = 0;
        int mx = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum += (A[i] = rd());
            if(++cnt[A[i]] >= 2)
                mx = max(mx, A[i]);
            A[i] = mx;
        }
        mx = 0;
        cnt.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            sum += A[i];
            if(++cnt[A[i]] >= 2)
                mx = max(mx, A[i]);
            A[i] = mx;
        }
        cnt.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            ++cnt[A[i]];
        ll now = 0, len = 0;
        for (int i = n; i >= 0; --i)
        {
            len += cnt[i];
            ll area = len * (len + 1)/ 2;
            ll has = area - now;
            sum += has * i;
            now = area;
        }
        cout << sum << '\n';
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
/*
2 1 1 2
0 0 1 2
0 0 0 0


4 4 4 4 5 5 5
0 4 4 4 4 5 5
0 0 4 4 4 4 5
0 0 0 4 4 4 4
0 0 0 0 4 4 4
0 0 0 0 0 4 4
0 0 0 0 0 0 4

x x y y y y y z z z z
*/
