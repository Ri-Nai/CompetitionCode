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

    auto SPFA = [&](int S)
    {
        vector<int> cnt(n + 1);
        vector<int> in(n + 1);
        dis[S] = 0, in[S] = 1;
        queue<int> Q;
        Q.push(S);
        while (!Q.empty()) // 直到所有点都不需要松弛了
        {
            int u = Q.front();
            Q.pop();
            in[u] = 0;
            for (auto [v, w] : E[u])
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!in[v])
                    {
                        // 入队了多少次就是松弛了多少轮，松弛了n轮就是有负环
                        in[v] = 1;
                        if (++cnt[v] == n)
                            return 1;
                        Q.push(v);
                    }
                }
        }
        return 0;
    };
}
