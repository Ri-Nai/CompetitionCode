#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    auto solve = [&]()
    {
        int n, m, X;
        scanf("%d%d%d", &n, &m, &X);
        vector<vector<pair<int, int>>> E(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int A, B, C, D;
            scanf("%d%d%d%d", &A, &B, &C, &D);
            if (A == B && C == D)
            {
                E[A].emplace_back(D, X);
                E[D].emplace_back(A, -X);
            }
            else
            {
                E[D].emplace_back(A, - X - 1);
                E[B].emplace_back(C, X - 1);
            }
        }
        for (int i = 1; i < n; ++i)
            E[i + 1].emplace_back(i, -1);
        vector<ll> dis(n + 1, 0);
        queue<int> Q;
        vector<int> in(n + 1), vis(n + 1);
        for (int i = 1; i <= n; ++i)
            Q.push(i), dis[i] = 0, vis[i] = 1;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 0;
            for (auto [v, w] : E[u])
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                    {
                        if (++in[v] == n + 2)
                        {
                            puts("IMPOSSIBLE");
                            return;
                        }
                        vis[v] = 1;
                        Q.push(v);
                    }
                }
        }
        for (int i = 2; i <= n; ++i)
            cout << dis[i] - dis[i - 1] << " \n"[i == n];
    };
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: ", i), solve();
}
/*
*/
