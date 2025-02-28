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
        const int S = (1 << 18) - 1;
        int n = rd(), m = rd(), k = rd();
        vector<vector<pair<int, int>>> E(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            int now = S ^ i;
            while (now)
            {
                int p = now & -now;
                if ((p ^ i) > n)
                    break;
                E[i].emplace_back(p ^ i, p * k);
                E[p ^ i].emplace_back(i, -p * k);
                now ^= p;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), w = rd();
            E[u].emplace_back(v, w);
        }
        vector<ll> dis(n + 1, 1e18);
        auto Dijkstra = [&](int S)
        {
            dis[S] = 0;
            vector<int> vis(n + 1);
            priority_queue<pair<ll, int>> Q;
            Q.push({-dis[1], 1});
            // 小根堆
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
                    }
            }
        };
        Dijkstra(1);
        for (int i = 2; i <= n; ++i)
            cout << dis[i] << " \n"[i == n];
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
