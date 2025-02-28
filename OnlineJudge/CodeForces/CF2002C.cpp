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
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd(), Y[i] = rd();
        int XS = rd(), YS = rd(), XT = rd(), YT = rd();
        auto dis = [&](int x1, int y1, int x2, int y2) -> ll
        {
            return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
        };
        ll D = dis(XS, YS, XT, YT);
        for (int i = 1; i <= n; ++i)
        {
            if (dis(X[i], Y[i], XT, YT) <= D)
                End("NO");
        }
        End("YES");
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
