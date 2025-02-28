#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> edge(n + 1);
    vector<int> L(n + 1), R(n + 1),
        dep(n + 1), fa(n + 1), sz(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int num = 0;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        L[u] = ++num;
        fa[u] = f;
        sz[u] = 1;
        dep[u] = dep[f] + 1;
        for (int v : edge[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        R[u] = num;
    };
    dfs(dfs, 1, 0);
    auto solve = [&]()
    {
        auto isAscent = [&](int u, int v)
        {
            return L[u] >= L[v] && L[u] <= R[v];
        };
        auto isValid = [&](int u, int v)
        {
            return isAscent(u, fa[v]) && !isAscent(u, v) && fa[v] != u;
        };
        auto inValid = [&](int u, int v)
        {
            return isAscent(u, v);
        };
        int m;
        scanf("%d", &m);
        vector<int> series(m + 1);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &series[i]);
        auto cop = series;
        sort(cop.begin() + 1, cop.end());
        for (int i = 2; i <= m; ++i)
            if (cop[i] == cop[i - 1])
                return false;
        vector<int> need;
        need.push_back(1);

        for (int i = 2; i <= m; ++i)
            if(isValid(series[1], series[i]))
                need.push_back(i);
            else if (inValid(series[1], series[i]))
                return false;

        for (int i = 1; i < need.size(); ++i)
            if (need[i] - need[i - 1] != sz[series[need[i - 1]]])
                return false;
        for (int i = 1; i < need.size(); ++i)
            if (dep[series[need[i]]] > dep[series[need[i - 1]]])
                return false;

        int pos = 1, flag = 1;
        auto dfs = [&](auto &&self, int u) -> void
        {
            ++pos;
            if (!flag)
                return;
            if (pos == m + 1)
                return;
            int v = series[pos];
            int cnt = 0;
            while (flag && pos != m + 1 && fa[series[pos]] == u)
                ++cnt, self(self, series[pos]);
            if (pos != m + 1 && cnt != edge[u].size() - (u != 1))
                flag = 0;
        };
        for (int u : need)
        {
            int last = pos;
            dfs(dfs, series[u]);
            if (pos == m + 1)
                return true;
            if (!flag)
                return false;
            if (pos - last != sz[series[u]])
                return false;
        }
        return pos == m + 1;
    };
    while (q--)
        if (solve())
            puts("Yes");
        else puts("No");
}
