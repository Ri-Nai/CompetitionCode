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
        int x = rd(), y = rd();
        int ans = 1e9;
        for (int j = 0; j <= 99; ++j)
            for (int k = 0; k <= 99; ++k)
            {
                int x0 = j * 11 + k * 7;
                int y0 = j + k * 2;
                if (y0 >= y)
                {
                    int i = (x - x0 - 1) / 15 + 1;
                    if (x0 >= x) i = 0;
                    ans = min(i + j + k, ans);
                }
            }
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
