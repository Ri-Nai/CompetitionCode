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
        int n = rd(), m = rd(), Q = rd();
        vector<tuple<int, int, int>> edge(1), que(1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), w = rd();
            edge.emplace_back(u, v, w);
        }
        vector<int> mark(m + 1);
        for (int i = 1; i <= Q; ++i)
        {
            int type = rd(), x = rd(), y = 0;
            if (type == 2)
                y = rd();
            else
                mark[x] = 1;
            que.emplace_back(type, x, y);
        }
        auto Min = [&](auto &x, auto y)
        {
            if (y < x)
                x = y;
            return x;
        };
        const ll inf = 1e18;
        vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, inf));
        vector<ll> ans;
        for (int i = 1; i <= m; ++i)
            if (!mark[i])
            {
                auto [u, v, w] = edge[i];
                Min(dis[u][v], w);
                Min(dis[v][u], w);
            }
        for (int i = 1; i <= n; ++i)
            Min(dis[i][i], 0);
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    Min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = Q; i >= 1; --i)
        {
            auto [type, x, y] = que[i];
            if (type == 2)
                ans.push_back(dis[x][y] == inf ? -1 : dis[x][y]);
            else
            {
                auto [u, v, w] = edge[x];
                for (int p = 1; p <= n; ++p, cout << "\n")
                    for (int q = 1; q <= n; ++q)
                        Min(dis[p][q], dis[p][u] + w + dis[v][q]),
                        Min(dis[p][q], dis[p][v] + w + dis[u][q]);
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << '\n';
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
