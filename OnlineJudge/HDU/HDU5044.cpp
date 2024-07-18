#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5;
LL C[2][N];
int nxt[N << 1], head[N], to[N << 1], U[N], V[N], tot;
int n, m, top[N], fa[N], son[N], sz[N], id[N], dep[N], num;
void Add(int k, int x, int y)
{
    while (x <= n)
        C[k][x] += y, x += x & -x;
}
void Add(int u, int v)
{
    nxt[++tot] = head[u];
    to[tot] = v;
    head[u] = tot;
}
LL Sum(int k, int x)
{
    LL res = 0;
    while (x)
        res += C[k][x], x ^= x & -x;
    return res;
}
void dfs(int u, int f)
{
    sz[u] = 1;
    son[u] = 0;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (int i = head[u]; i; i = nxt[i])
    {
        int &v = to[i];
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
    for (int i = head[u]; i; i = nxt[i])
        if (to[i] != son[u] && to[i] != fa[u])
            _dfs(to[i], to[i]);
}
void updata(int k, int u, int v, int w)
{
    while (top[u] ^ top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        Add(k, id[top[u]], w);
        Add(k, id[u] + 1, -w);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    if (k)
        Add(k, id[u], w), Add(k, id[v] + 1, -w);
    else if (u != v)
        Add(k, id[son[u]], w), Add(k, id[v] + 1, -w);
}
void solve(int cas)
{
    scanf("%d%d", &n, &m);
    memset(head, 0, sizeof head);
    memset(C, 0, sizeof C);
    tot = num = 0;
    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &U[i], &V[i]),
            Add(U[i], V[i]), Add(V[i], U[i]);
    dfs(1, 0);
    _dfs(1, 1);
    for (int i = 1; i < n; ++i)
        if (dep[U[i]] < dep[V[i]])
            swap(U[i], V[i]);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        char s[10];
        scanf("%s", s);
        scanf("%d%d%d", &u, &v, &w);
        updata(s[3] == '1', u, v, w);
    }
    printf("Case #%d:\n", cas);
    printf("%lld", Sum(1, id[1]));
    for (int i = 2; i <= n; ++i)
        printf(" %lld", Sum(1, id[i]));
    puts("");
    if (n > 1)
        printf("%lld", Sum(0, id[U[1]]));
    for (int i = 2; i < n; ++i)
        printf(" %lld", Sum(0, id[U[i]]));
    puts("");
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve(i);
}
