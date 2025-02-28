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
        int x0, y0, r;
        cin >> x0 >> y0 >> r;
        int n, t;
        cin >> n >> t;
        typedef long double db;
        vector<pair<db, int>>has;
        auto get = [&](auto xs, auto ys, auto xe, auto ye, auto v)
        {
            auto x = xe - xs;
            auto y = ye - ys;
            auto l = sqrt(x * x + y * y);
            auto px = v * x / l;
            auto py = v * y / l;
            auto calc = [&](auto a, auto b, auto c) -> pair<db, db>
            {
                auto delta = b * b - 4 * a * c;
                if (delta + 1e-10 < 0)
                    return {-1., -1.};
                auto x1 = (-b + sqrt(delta)) / 2 / a;
                auto x2 = (-b - sqrt(delta)) / 2 / a;
                if (x1 > x2)
                    swap(x1, x2);
                if (x1 < 0)
                    return {-1., -1.};
                // cout << x1 << ' ' << x2 << '\n';
                return {x1, x2 + t};
            };
            auto xx = x0 - xs;
            auto yy = y0 - ys;
            auto now = calc(px * px + py * py, -2 * (xx * px + yy * py), xx * xx + yy * yy - r * r);
            if (now.first < 0)
                return;
            has.emplace_back(now.first, 1);
            has.emplace_back(now.second, -1);
        };
        for (int i = 1; i <= n; ++i)
        {
            db xs, ys, xe, ye, v;
            cin >> xs >> ys >> xe >> ye >> v;
            get(xs, ys, xe, ye, v);
        }
        sort(has.begin(), has.end());
        int now = 0;
        db bg = 0, ans = 0;
        for (auto [x, p] : has)
        {
            if (p == 1)
            {
                if (!now++)
                    bg = x;
            }
            else
            {
                if (!--now)
                    ans += x - bg;
            }
        }
        // cout << ans << '\n';
        printf("%.10LF\n", ans);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
