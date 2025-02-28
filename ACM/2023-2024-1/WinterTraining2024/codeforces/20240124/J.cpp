#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout << X << '\n', void()
bool Nai;
namespace T
{
    const int N = 2e5 + 5;
    int blk, num, n, m, q;
    int blg[N], low[N], dfn[N], stk[N], top;
    int A[N], B[N], tot, vis[N], dep[N];
    int tp[N], sz[N], son[N], state[N];
    int fa[N];
    struct Edge
    {
        int v, w, id;
    };
    vector<Edge> E[N], P[N];
    int rd()
    {
        int t = 0, c, f = 0;
        while (!isdigit(c = getchar()))
            f |= c == '-';
        while (isdigit(c))
            t = (t << 1) + (t << 3) + (c ^ 48), c = getchar();
        return f ? -t : t;
    }
    void Tarjan(int u, int f)
    {
        dfn[stk[++top] = u] = low[u] = ++num;
        state[u] = top;
        for (auto [v, w, id] : E[u])
        {
            if (id == f)
                continue;
            if (!dfn[v])
                Tarjan(v, id), low[u] = min(low[u], low[v]);
            else
            {
                low[u] = min(low[u], dfn[v]);
                int size = state[u] - state[v] + 1;
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            ++blk;
            do
                blg[v = stk[top--]] = blk;
            while (u ^ v);
        }
    }
    void dfs(int u, int f)
    {
        vis[u] = 1;
        fa[u] = f;
        sz[u] = 1;
        dep[u] = dep[f] + 1;
        for (auto [v, w, id] : P[u])
        {
            if (v == f)
                continue;
            if (!vis[v])
            {
                dfs(v, u), sz[u] += sz[v];
                if (sz[v] > sz[son[u]])
                    son[u] = v;
            }
            B[v] |= w;
        }
    }
    void dfs_(int u, int f, int t)
    {
        vis[u] = 1;
        A[u] += A[f];
        B[u] += B[f];
        tp[u] = t;
        if (son[u])
            dfs_(son[u], u, t);
        for (auto [v, w, id] : P[u])
        {
            if (v == f)
                continue;
            if (v != son[u] and !vis[v])
                dfs_(v, u, v);
        }
    }
    int LCA(int u, int v)
    {
        while (tp[u] ^ tp[v])
            if (dep[tp[u]] > dep[tp[v]])
                u = fa[tp[u]];
            else
                v = fa[tp[v]];
        return dep[u] < dep[v] ? u : v;
    }
    void solve()
    {
        n = rd(), m = rd(), q = rd();
        tot = blk = num = 0;
        for (int i = 1; i <= n; ++i)
            E[i].clear(), dfn[i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd(), w = rd();
            E[u].push_back({v, w, i});
            E[v].push_back({u, w, i});
        }
        for (int i = 1; i <= n; ++i)
            if (!dfn[i])
                Tarjan(i, 0);
        for (int i = 1; i <= blk; ++i)
            son[i] = vis[i] = B[i] = A[i] = 0, P[i].clear();
        for (int u = 1; u <= n; ++u)
            for (auto [v, w, id] : E[u])
                if (blg[u] == blg[v])
                    A[blg[u]] |= w;
                else
                    P[blg[u]].push_back({blg[v], w, id});
        dfs(1, 0);
        for (int i = 1; i <= blk; ++i)
            vis[i] = 0;
        dfs_(1, 0, 1);
        for (int u, v; q--;)
        {
            u = blg[rd()];
            v = blg[rd()];
            int l = LCA(u, v);
            int f = fa[l];
            int a = A[u] + A[v] - A[f] - A[l];
            int b = B[u] + B[v] - B[l] - B[l];
            if (a | b)
                cout << "wow!golden legendary!\n";
            else
                cout << "awsl!\n";
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
