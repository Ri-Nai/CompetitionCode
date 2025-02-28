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
        vector<string> M(n + 1, ".");
        for (int i = 1; i <= n; ++i)
        {
            string s;
            cin >> s;
            M[i] += s;
        }
        int mxl = 0, mxd = 0;
        for (int i = 1; i <= n; ++i)
        {
            int l = 0;
            for (int j = 1; j <= m; ++j)
                l += M[i][j] == 'x';
            mxl = max(l, mxl);
        }
        for (int i = 1; i <= m; ++i)
        {
            int l = 0;
            for (int j = 1; j <= n; ++j)
                l += M[j][i] == 'x';
            mxd = max(l, mxd);
        }
        int g = gcd(mxl, mxd);
        mxl /= g;
        mxd /= g;
        for (int i = 1; i <= mxd; ++i, putchar('\n'))
            for (int j = 1; j <= mxl; ++j)
                putchar('x');
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    // T::solve();
}
