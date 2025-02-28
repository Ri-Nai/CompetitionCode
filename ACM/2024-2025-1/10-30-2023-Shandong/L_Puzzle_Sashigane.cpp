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
        int n, x, y;
        cin >> n >> x >> y;
        int len = 1;
        int x1 = x, x2 = x, y1 = y, y2 = y;
        vector<tuple<int, int, int, int>> ans;
        while (x1 > 1 && y1 > 1)
            ans.emplace_back(--x1, --y1, 1, 1);
        while (x1 > 1 && y2 < n)
            ans.emplace_back(--x1, ++y2, 1, -1);
        while (x2 < n && y1 > 1)
            ans.emplace_back(++x2, --y1, -1, 1);
        while (x2 < n && y2 < n)
            ans.emplace_back(++x2, ++y2, -1, -1);
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (auto [x, y, xp, yp] : ans)
        {
            cout << x << ' ' << y << ' ' << xp * len << ' ' << yp * len << '\n';
            ++len;
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
