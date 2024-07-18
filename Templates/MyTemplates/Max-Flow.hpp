#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
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
namespace Max_Flow
{
    const int N = 205;
    const int M = 1e4 + 5;
    int n, m, S, T;
    int tot = 1, head[N], Now[N], nxt[M], V[M], W[M];
    int bfn[N];
    bool vis[N];
    void Add(int u, int v, int w)
    {
        nxt[++tot] = head[u];
        V[head[u] = tot] = v;
        W[tot] = w;
    }
    bool BFS()
    {
        queue<int> Q;
        Q.push(S);
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        vis[S] = 1;
        bool flag = 0;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = V[i], w = W[i];
                if (w == 0)
                    continue;
                if (vis[v])
                    continue;
                vis[v] = 1;
                bfn[v] = bfn[u] + 1;
                if (v == T)
                    flag = 1;
                Q.push(v);
            }
        }
        return flag;
    }
    int dfs(int u, int f)
    {
        if (u == T)
            return f;
        for (int i = Now[u]; i; i = nxt[i])
        {
            int v = V[i], w = W[i];
            Now[u] = i;
            if (w == 0)
                continue;
            if (bfn[v] != bfn[u] + 1)
                continue;
            int now = dfs(v, min(w, f));
            if (now == 0)
            {
                bfn[v] = -1;
                continue;
            }
            W[i] -= now;
            W[i ^ 1] += now;
            return now;
        }
        return 0;
    }
    ll max_flow()
    {
        ll res = 0;
        while (BFS())
        {
            int now = 0;
            for (int i = 1; i <= n; ++i)
                Now[i] = head[i];
            while (now = dfs(S, 1e9))
                res += now;
        }
        return res;
    }
    void solve()
    {
        cin >> n >> m >> S >> T;
        for (int i = 1; i <= m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            Add(u, v, w);
            Add(v, u, 0);
        }
        cout << max_flow() << '\n';
    }
}
