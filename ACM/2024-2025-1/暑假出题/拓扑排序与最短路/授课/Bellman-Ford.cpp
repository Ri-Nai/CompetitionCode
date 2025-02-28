#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, S = 1;//源点的位置，很多题都是1吧
    cin >> n >> m >> S;
    typedef long long ll;
    vector<ll> dis(n + 1, 1e18);
    dis[S] = 0;
    vector<array<int, 3>> E(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    bool flag = 0;
    for (int i = 1; i <= n; ++i)
    {
        flag = 0;
        for (int j = 1; j <= m; ++j)
        {
            auto [u, v, w] = E[i];
            if (dis[v] > dis[u] + w)
            {
                flag = 1;
                dis[v] = dis[u] + w;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
        puts("-1");//第i轮还在松弛，说明图中有负环
}
