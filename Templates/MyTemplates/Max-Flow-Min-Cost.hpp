#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
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
namespace Max_Flow_Min_Cost
{
    const int N = 5e5 + 5;
    const int M = 3e6 + 5;
    const ll inf = 1e18;
    int n, m, S, T;
    int tot = 1, head[N], nxt[M], V[M], W[M], C[M];
    int pre[N], preid[N];
    ll flow[N], dis[N];
    bool vis[N];
    void Add(int u, int v, int w, int c)
    {
        nxt[++tot] = head[u];
        V[head[u] = tot] = v;
        W[tot] = w;
        C[tot] = c;
    }
    bool BFS()
    {
        queue<int> Q;
        for (int i = 1; i <= n; ++i)
            flow[i] = 0, dis[i] = inf, vis[i] = 0;
        flow[S] = inf, dis[S] = 0, vis[S] = 1;
        Q.push(S);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = V[i], w = W[i], c = C[i];
                if (w == 0)
                    continue;
                if (dis[v] <= dis[u] + c)
                    continue;
                dis[v] = dis[u] + c;
                flow[v] = min(flow[u], 0ll + w);
                pre[v] = u;
                preid[v] = i;
                if (!vis[v])
                    vis[v] = 1, Q.push(v);
            }
        }
        if (flow[T] == 0)
            return 0;
        if (dis[T] == inf)
            return 0;
        return 1;
    }
    void max_flow()
    {
        ll res = 0, cost = 0;
        while (BFS())
        {
            int u = T;
            while (u != S)
            {
                int id = preid[u];
                W[id] -= flow[T];
                W[id ^ 1] += flow[T];
                u = V[id ^ 1];
            }
            res += flow[T];
            cost += flow[T] * dis[T];
        }
        cout << res << ' ' << cost << '\n';
    }
    void solve()
    {
        cin >> n >> m >> S >> T;
        for (int i = 1; i <= m; ++i)
        {
            int u, v, w, c;
            cin >> u >> v >> w >> c;
            Add(u, v, w, c);
            Add(v, u, 0, -c);
        }
        max_flow();
    }
}
