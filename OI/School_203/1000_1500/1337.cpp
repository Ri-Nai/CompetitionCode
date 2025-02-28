#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define pr pair<int, int>
#define mp make_pair
using namespace std;
const int maxn = 105, maxm = maxn * maxn, inf = 0x3f3f3f3f;

int n, m;

int head[maxm], cnt, to[maxm], from[maxm], val[maxm], nxt[maxm];

inline void Add(int u, int v, int w)
{
    from[++cnt] = u;
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void nxt_in_put()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; ++i)
        scanf("%d%d%d", &u, &v, &w),
            Add(u, v, w);
}

namespace Floyd
{
    int dis[maxn][maxn];
    void in_put()
    {
        scanf("%d%d", &n, &m);
        memset(dis, inf, sizeof dis);
        for (int i = 1, u, v, w; i <= m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (w < dis[u][v])
                dis[u][v] = w;
        }
    }
    void solve()
    {
        in_put();
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        printf("%d\n", dis[1][n] == inf ? -1 : dis[1][n]);
    }
};
namespace BellmanFord
{
    int dis[maxn];
    void solve()
    {
        nxt_in_put();
        memset(dis, inf, sizeof dis);
        dis[1] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int u = from[j], v = to[j], w = val[j];
                if (dis[u] + w < dis[v])
                    dis[v] = dis[u] + w;
            }
        printf("%d\n", dis[n] == inf ? -1 : dis[n]);
    }
}
namespace SPFA
{
    int dis[maxn];
    bool vis[maxn];
    void solve()
    {
        nxt_in_put();
        memset(dis, inf, sizeof dis);
        memset(vis, 0, sizeof vis);
        dis[1] = 0;
        vis[1] = 1;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = to[i], w = val[i];
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                        vis[v] = 1, Q.push(v);
                }
            }
        }
        printf("%d\n", dis[n] == inf ? -1 : dis[n]);
    }
}
namespace Dijkstra
{
    int dis[maxn];
    bool vis[maxn];
    void solve()
    {
        nxt_in_put();
        memset(dis, inf, sizeof dis);
        memset(vis, 0, sizeof vis);
        priority_queue<pr, vector<pr>, greater<pr>> Q;
        dis[1] = 0;
        Q.push(mp(0, 1));
        while (!Q.empty())
        {
            int u = Q.top().second;
            Q.pop();
            if (!vis[u])
            {
                vis[u] = 1;
                for (int i = head[u]; i; i = nxt[i])
                {
                    int v = to[i], w = val[i];
                    if (dis[v] > dis[u] + w)
                        dis[v] = dis[u] + w, Q.push(mp(dis[v], v));
                }
            }
        }
        printf("%d\n", dis[n] == inf ? -1 : dis[n]);
    }
}
int main()
{
    BellmanFord::solve();
}
