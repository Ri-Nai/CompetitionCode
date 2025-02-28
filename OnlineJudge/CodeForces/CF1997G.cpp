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
        int t0 = rd(), t1 = rd(), t2 = rd();
        vector<vector<tuple<int, int, int>>> E(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), w1 = rd(), w2 = rd();
            E[u].emplace_back(v, w1, w2);
            E[v].emplace_back(u, w1, w2);
        }
        auto dijkstra = [&](int S, int T)
        {
            vector<int> dis(n + 1, -1);
            vector<int> vis(n + 1, 0);
            dis[S] = t0;
            priority_queue<pair<int, int>> Q;
            Q.push({dis[S], S});
            while (!Q.empty())
            {
                auto [now, u] = Q.top();
                Q.pop();
                if (vis[u])
                    continue;
                vis[u] = 1;
                auto Modify = [&](int v, int w)
                {
                    if (dis[v] < w)
                        Q.push({dis[v] = w, v});
                };
                for (auto [v, w1, w2] : E[u])
                {
                    if (now >= t2 && now - w1 < t2 || now > t1 && now < t2)
                        Modify(v, max(now - w2, t1 - w1));
                    else Modify(v, max(now - w1, now - w2));
                }
            }
            return dis[T];
        };
        cout << dijkstra(n, 1) << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
