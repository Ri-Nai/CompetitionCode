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
        struct Point
        {
            int x, y;
            Point() {}
            Point(int _, int __) { x = _, y = __; }
            void input()
            {
                x = rd();
                y = rd();
            }
            Point operator-(const Point &_) const
            {
                return Point(x - _.x, y - _.y);
            }
            bool onLine(const Point &P1, const Point &P2) const
            {
                return (*this - P1).cross(*this - P2) == 0;
            }
            long long cross(const Point &_) const
            {
                return 1ll * x * _.y - 1ll * y * _.x;
            }
            long long dis(const Point &_) const
            {
                return 1ll * (x - _.x) * (x - _.x) + 1ll * (y - _.y) * (y - _.y);
            }
        };
        vector<Point> has;
        for (int i = 0; i < n; ++i)
        {
            Point p;
            p.input();
            has.push_back(p);
        }
        int m = n + n;
        auto dp = vector(m, vector<long long>(m));
        has.insert(has.end(), has.begin(), has.end());
        for (int len = 1; len <= n; ++len)
            for (int l = 0, r = len; r < m; ++l, ++r)
                dp[l][r] = max(has[l].dis(has[r]), max(dp[l + 1][r], dp[l][r - 1]));
        long long ans = 8e18;
        for (int l = 0; l < n; ++l)
        {
            int r = l + n;
            for (int mid = l + 2; mid <= r - 2; ++mid)
            {
                if (has[mid].onLine(has[l], has[l + 1]) || has[mid].onLine(has[r], has[r - 1]))
                    continue;
                // cout << l << ' ' << mid << ' ' << r << ' ' << dp[l][mid] << ' ' << dp[mid][r] << endl;
                ans = min(ans, dp[l][mid] + dp[mid][r]);
            }
        }
        cout << ans << endl;
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
