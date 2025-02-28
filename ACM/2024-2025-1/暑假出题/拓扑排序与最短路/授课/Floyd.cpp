#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    typedef long long ll;
    vector<vector<ll>>dis(n + 1, vector<ll>(n + 1, 1e18));
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], 0ll + w);
        //如果是无向图的话
        dis[v][u] = min(dis[v][u], 0ll + w);
    }
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
