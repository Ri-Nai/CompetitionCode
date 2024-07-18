#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int nxt[N << 1], head[N], to[N << 1], tot;
int n, m, A[N], son[N], sz[N], fa[N], L[N], R[N], Re[N], num, B[N], cnt[N], res[N], ans[N];
vector<int> Q[N];
inline void Add(int u, int v)
{
    nxt[++tot] = head[u];
    to[tot] = v, head[u] = tot;
}
void dfs(int u, int f)
{
    fa[u] = f;
    son[u] = 0;
    sz[u] = 1;
    Re[L[u] = ++num] = u;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
    {
        if (v == f)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
    R[u] = num;
}
inline void Del(int u)
{
    for (int i = L[u]; i <= R[u]; ++i)
        --res[cnt[A[Re[i]]]--];
}
inline void Add(int u)
{
    for (int i = L[u]; i <= R[u]; ++i)
        ++res[++cnt[A[Re[i]]]];
}
void _dfs(int u)
{
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && v != son[u])
            _dfs(v), Del(v);
    if (son[u])
        _dfs(son[u]);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && v != son[u])
            Add(v);
    ++res[++cnt[A[u]]];
    for (int i = 0; i < Q[u].size(); ++i)
        ans[Q[u][i]] = res[B[Q[u][i]]];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &u, &v), Add(u, v), Add(v, u);
    for (int i = 1, u; i <= m; ++i)
        scanf("%d%d", &u, &B[i]), Q[u].push_back(i);
    dfs(1, 0);
    _dfs(1);
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
}
