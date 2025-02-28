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
        vector<vector<int>> E(n + 1);
        vector<ll> bs(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            bs[u] |= 1ll << v;
            E[v].push_back(u);
            bs[v] |= 1ll << u;
        }
        struct point
        {
            ll vis;
            int now;
            point(int u)
            {
                vis = 1ll << u;
                now = u;
            }
            point(ll t, int u)
            {
                vis = t;
                now = u;
            }
        };
        auto get_count = [&](ll x)
        {
            int res = 0;
            for (int i = 1; i <= 40; ++i)
                res += x >> i & 1;
            return res;
        };
        queue<point> Q;
        for (int i = 1; i <= n; ++i)
            Q.push(point(i));
        int ans = 0;
        while (!Q.empty())
        {
            auto [vis, u] = Q.front();
            Q.pop();
            if (Q.empty())
                ans = get_count(vis);
            for (int i : E[u])
            {
                if ((vis >> i & 1))
                    continue;
                bool flag = 1;
                ll has = vis & bs[i];
                if (has & (1ll << u))
                    has ^= 1ll << u;
                if (has)
                    continue;
                auto t = vis;
                t |= 1ll << i;
                auto next = point(t, i);
                Q.push(next);
            }
        }
        cout << ans << '\n';
    }
}
bool Ri;
void print_time()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("当前时间：%s", asctime(timeinfo));

}
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // print_time();
    // freopen("1.in", "r", stdin);

    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
    // print_time();

}
