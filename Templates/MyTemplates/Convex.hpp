#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    struct Point
    {
        typedef Point Vec;
        int x, y;
        Point() {}
        Point(int x, int y) : x(x), y(y) {}
        void input()
        {
            cin >> x >> y;
        }
        Vec operator-(const Point &_) const
        {
            return Vec(x - _.x, y - _.y);
        }
        long long operator*(const Vec &_) const
        {
            return 1ll * x * _.y - 1ll * y * _.x;
        }
        bool operator<(const Point &_) const
        {
            return make_pair(x, y) < make_pair(_.x, _.y);
        }
    };
    typedef Point Vec;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i)
        p[i].input();
    sort(p.begin(), p.end());
    vector<int> vis(n);
    auto getConvex = [&](const vector<Point> &p)
    {
        vector<int> stk;
        vector<Point> convex;
        int top = 0;
        if (p.size() <= 2)
            return p;
        int basic = 1;
        auto work = [&](const int &id)
        {
            const Point &x = p[id];
            while (top > basic && (convex[top - 1] - convex[top - 2]) * (x - convex[top - 2]) <= 0)
                --top, convex.pop_back(), --vis[stk.back()], stk.pop_back();
            ++top;
            ++vis[id];
            stk.push_back(id);
            convex.push_back(x);
        };
        for (int i = 0; i < p.size(); ++i)
            work(i);
        basic = top;
        for (int i = p.size() - 2; i >= 0; --i)
            work(i);
        convex.pop_back();
        --vis[stk.back()];
        stk.pop_back();
        return convex;
    };
    auto outside = getConvex(p);
    auto nxt = [&](int i, int n)
    {
        return (i + 1) % n;
    };
    auto pre = [&](int i, int n)
    {
        return (i - 1 + n) % n;
    };
    auto sqr = [&](int i, const Point &x)
    {
        return llabs((outside[nxt(i, n)] - outside[i]) * (x - outside[i]));
    };
}
