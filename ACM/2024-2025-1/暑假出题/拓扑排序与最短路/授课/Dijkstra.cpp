#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, S = 1; // 源点的位置，很多题都是1吧
    cin >> n >> m >> S;
    typedef long long ll;
    vector<ll> dis(n + 1, 1e18);
    vector<vector<pair<int, int>>> E(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(v, w);
    }

    auto Dijkstra = [&](int S)
    {
        dis[S] = 0;
        vector<int> vis(n + 1);
        priority_queue<pair<ll, int>> Q;
        Q.push({0, S});
        //小根堆
        while (!Q.empty()) // 直到所有点都不需要松弛了
        {
            auto [now, u] = Q.top();
            Q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [v, w] : E[u])
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    Q.push({-dis[v], v});
                    //塞入负数的原因是优先队列默认降序，而我们要求升序
                    //pair的前后的成员分别是第一关键词和第二关键词
                }
        }
    };
}
