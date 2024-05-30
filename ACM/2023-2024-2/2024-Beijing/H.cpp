#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int n = rd();
    vector<vector<int>> fa(n + 1, vector<int>(20));
    vector<int> dep(n + 1);
    for (int i = 2; i <= n; ++i)
        dep[i] = dep[fa[i][0] = rd()] + 1;
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j <= n; ++j)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    auto LCA = [&] (int u, int v)
    {
        for (int i = 19; i >= 0; --i)
            if (fa[u][i] ^ fa[v][i])
                u = fa[u][i], v = fa[v][i];
        return make_pair(u, v);
    };
    auto Solve = [&]()
    {
        int m = rd();
        vector<int> P;
        for (int i = 0; i < m; ++i)
            P.push_back(rd());
        vector<int>in(n + 1);
        vector<vector<int>> E(n + 1);
        for (int i = 1; i < m; ++i)
        {
            int u = P[i], v = P[i - 1];
            if (dep[u] < dep[v])
                return false;
            if (dep[u] > dep[v])
                continue;
            auto [x, y] = LCA(u, v);
            E[x].push_back(y);
            ++in[y];
        }
        int cnt = 0;
        queue<int>Q;
        for (int i = 1; i <= n; ++i)
            if (!in[i])
                Q.push(i);
        while (!Q.empty())
        {
            ++cnt;
            int u = Q.front();
            Q.pop();
            for (int v : E[u])
                if (!--in[v])
                    Q.push(v);
        }
        return cnt == n;
    };
    int T = rd();
    while (T--)
        puts(Solve() ? "Yes" : "No");
}
