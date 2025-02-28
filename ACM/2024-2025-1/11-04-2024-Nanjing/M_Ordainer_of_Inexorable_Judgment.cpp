#include <bits/stdc++.h>
using namespace std;
namespace T
{
    #define double long double
    void solve()
    {
        int n, x0, y0, d, t;
        cin >> n >> x0 >> y0 >> d >> t;
        const double pi = acosl(-1);
        struct Point
        {
            typedef Point Vec;
            int x, y;
            Point(){}
            Point(int _, int __) : x{_}, y{__} {}
            double angle()
            {
                return atan2l(y, x);
            }
            long long operator * (const Vec &_)const
            {
                return 1ll * x * _.y - 1ll * y * _.x;
            }
            void input()
            {
                scanf("%d%d", &x, &y);
            }
            double dis()
            {
                return sqrtl(1ll * x * x + 1ll * y * y);
            }
        };
        auto diffangle = [&](Point a)
        {
            return asinl(d / a.dis());
        };
        vector<Point> P(n + 1);
        for (int i = 1; i <= n; ++i)
            P[i].input();
        double mxrange = 0, L, R;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                double l = P[i].angle() - diffangle(P[i]);
                double r = P[j].angle() + diffangle(P[j]);
                double now = r - l;
                if (now < 0)
                {
                    if (r - l + 2 * pi > 0)
                        now = r - l + 2 * pi, l -= 2 * pi;
                }
                if (now > pi || now < 0)
                    continue;
                if (now > mxrange)
                    mxrange = now, L = l, R = r;
            }
        vector<pair<double, double>> ranges;
        ranges.emplace_back(L - 4 * pi, R - 4 * pi);
        ranges.emplace_back(L - 2 * pi, R - 2 * pi);
        ranges.emplace_back(L, R);
        ranges.emplace_back(L + 2 * pi, R + 2 * pi);
        ranges.emplace_back(L + 4 * pi, R + 4 * pi);
        int rounds = t / pi / 2;
        double ans = rounds * mxrange;
        double last = t - rounds * pi * 2;
        double nowAngle = Point(x0, y0).angle();
        for (auto [l, r] : ranges)
        {
            double ln = nowAngle;
            double rn = nowAngle + last;
            ans += max(0.l, min(rn, r) - max(ln, l));
        }
        printf("%.12Lf\n", ans);
    }
}
int main()
{
    T::solve();
}
