#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<vector<pair<int, int>>> edge(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }
    int top = 0, tot = 0;
    vector<int> stk(n + 1);
    vector<int> dfn(n + 1), low(n + 1);

    vector<int> reid(n + 1);
    vector<int> first, nums;
    auto tarjan = [&](auto &&self, int u, int f) -> void
    {
        stk[++top] = u;
        dfn[u] = low[u] = ++tot;
        for (auto [v, w] : edge[u])
        {
            if (f == v)
                continue;
            if (!dfn[v])
                self(self, v, u), low[u] = min(low[u], low[v]);
            else
                low[u] = min(dfn[v], low[u]);
        }
        if (low[u] == dfn[u])
        {
            int v = -1;
            int idnow = first.size();
            first.emplace_back();
            nums.emplace_back();
            do
            {
                v = stk[top--];
                first[idnow] = v;
                nums[idnow] += a[v];
                reid[v] = idnow;
            } while (v ^ u);
        }
    };

    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(tarjan, i, -1);

    m = first.size();
    vector<vector<pair<int, int>>> Edge(m);
    for (int u = 1; u <= n; ++u)
        for (auto [v, w] : edge[u])
            if (reid[v] != reid[u])
                Edge[reid[u]].emplace_back(reid[v], w);
    vector<int> sz(m);
    vector<long long> vals(m);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = nums[u];
        vals[u] = 0;
        for (auto [v, w] : Edge[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            vals[u] += 1ll * sz[v] * w + vals[v];
        }
    };
    typedef pair<long long, int> Vid;
    auto dfs_ = [&](auto &&self, int u, int f, int pren, long long prev) -> Vid
    {

        Vid res = make_pair(vals[u] + prev, first[u]);
        for (auto [v, w] : Edge[u])
        {
            if (v == f)
                continue;
            int nxtn = pren + sz[u] - sz[v];
            long long nxtv = prev;
            nxtv += 1ll * nxtn * w;
            nxtv += vals[u] - vals[v] - 1ll * sz[v] * w;
            res = min(res, self(self, v, u, nxtn, nxtv));
        }
        return res;
    };
    dfs(dfs, 0, 0);
    cout << dfs_(dfs_, 0, 0, 0, 0).second << "\n";
    
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        nums[reid[x]] += y - a[x];
        a[x] = y;
        dfs(dfs, 0, 0);
        cout << dfs_(dfs_, 0, 0, 0, 0).second << "\n";
    }
}
/*
sigma sz * w
*/
