#include <bits/stdc++.h>
using namespace std;
int n, num;
vector<vector<int>> E(n + 1);
vector<int> top(n + 1), id(n + 1), sz(n + 1), son(n + 1), dep(n + 1), fa(n + 1);
void dfs(int u, int f)
{
    sz[u] = 1;
    son[u] = 0;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (auto v : E[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}
void _dfs(int u, int tp)
{
    top[u] = tp;
    id[u] = ++num;
    if (son[u])
        _dfs(son[u], tp);
    for (auto v : E[u])
        if (v != son[u] && v != fa[u])
            _dfs(v, v);
}
int LCA(int u, int v)
{
    while (top[u] ^ top[v])
        if (dep[top[u]] > dep[top[v]])
        // Modify id[top[u]] ... id[u]
            u = fa[top[u]];
        else
        // Modify id[top[v]] ... id[v]
            v = fa[top[v]];
    //Modify id[u] ... id[v]
    return dep[u] < dep[v] ? u : v;
}
