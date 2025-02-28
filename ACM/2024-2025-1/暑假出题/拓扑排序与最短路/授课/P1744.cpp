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
    double get_dis(int x1, int y1, int x2, int y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    void solve_Floyd()
    {
        int n = rd();
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd(), Y[i] = rd();
        vector<vector<double>> dis(n + 1, vector<double>(n + 1, 1e10));
        for (int i = 1; i <= n; ++i)
            dis[i][i] = 0;
        int m = rd();
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            dis[u][v] = dis[v][u] = get_dis(X[u], Y[u], X[v], Y[v]);
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int s = rd(), t = rd();
        printf("%.2f\n", dis[s][t]);
    }
    void solve_Bellman_Ford()
    {
        int n = rd();
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd(), Y[i] = rd();
        int m = rd();
        vector<tuple<int, int, double>> Edge; // tuple是三元组
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            double w = get_dis(X[u], Y[u], X[v], Y[v]);
            Edge.emplace_back(u, v, w);
            Edge.emplace_back(v, u, w);
        }
        vector<double> dis(n + 1, 1e10);
        int s = rd(), t = rd();
        dis[s] = 0;
        for (int i = 1; i < n; ++i)
            for (auto [u, v, w] : Edge)
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w;
        printf("%.2f\n", dis[t]);
    }
    void solve_SPFA()
    {
        int n = rd();
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd(), Y[i] = rd();
        int m = rd();
        vector<vector<pair<int, double>>> E(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            double w = get_dis(X[u], Y[u], X[v], Y[v]);
            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);
        }
        vector<double> dis(n + 1, 1e10);
        vector<bool> vis(n + 1);
        int s = rd(), t = rd();
        dis[s] = 0;
        vis[s] = 1;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            vis[u] = 0;
            Q.pop();
            for (auto [v, w] : E[u])
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                        vis[v] = 1, Q.push(v);
                }
        }
        printf("%.2f\n", dis[t]);
    }
    void solve_Dijkstra()
    {
        int n = rd();
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; ++i)
            X[i] = rd(), Y[i] = rd();
        int m = rd();
        vector<vector<pair<int, double>>> E(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            double w = get_dis(X[u], Y[u], X[v], Y[v]);
            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);
        }
        vector<double> dis(n + 1, 1e10);
        int s = rd(), t = rd();
        dis[s] = 0;
        priority_queue<pair<double, int>>Q;
        Q.push({0, s});
        vector<bool> vis(n + 1);
        while (!Q.empty())
        {
            auto [now, u] = Q.top();
            Q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [v, w] : E[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    Q.push({-dis[v], v});
                }
            }
        }
        printf("%.2f\n", dis[t]);
    }

}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve_SPFA();
}
