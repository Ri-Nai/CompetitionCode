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
namespace Max_Flow
{
    const int M = 1145141 + 5;
    const int N = M;
    int n, m, S, T;
    int tot = 1, head[N], Now[N], nxt[M], V[M], W[M], mark[M];
    int bfn[N];
    bool vis[N];
    void Add(int u, int v, int w)
    {
        nxt[++tot] = head[u];
        if (w == 1)
            mark[tot] = 1;
        V[head[u] = tot] = v;
        W[tot] = w;
    }
    void Add_net(int u, int v, int w)
    {
        Add(u, v, w);
        Add(v, u, 0);
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
    vector<int> get_ans()
    {
        vector<int> ans;
        for (int u = 1; u <= n; ++u)
        {
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = V[i];
                if (vis[u] && !vis[v] && mark[i])
                    ans.push_back(u + v + 1 >> 1);
            }
        }
        return ans;
    }
    void init(int num, int k)
    {
        T = n = k * 2 * num + 2;
        S = T - 1;
    }
}
namespace T
{
    void solve()
    {
        int n = rd(), m = rd(), k = rd();
        vector<int> in(n + 1), out(n + 1);
        // 2 * i - 1//入
        // 2 * i//出
        // 1 ~ 2n;
        // t * 2n + id
        const int inf = 1e9;
        auto get_id = [&](int x, int in, int k)
        {
            return x * 2 - in + k * 2 * n;
        };
        Max_Flow::init(n, k);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            ++out[u], ++in[v];
            for (int t = 0; t < k; ++t)
                Max_Flow::Add_net(get_id(u, 0, t), get_id(v, 1, t), inf);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!in[i])
                Max_Flow::Add_net(k * 2 * n + 1, get_id(i, 0, 0), inf);
            else if (!out[i])
                Max_Flow::Add_net(get_id(i, 1, k - 1), k * 2 * n + 2, inf);
            else for (int t = 0; t < k; ++t)
            {
                Max_Flow::Add_net(get_id(i, 1, t), get_id(i, 0, t), 1);
                if (t != k - 1)
                    Max_Flow::Add_net(get_id(i, 1, t), get_id(i, 0, t + 1), inf);
            }
        }
        ll res = Max_Flow::max_flow();
        if (res >= inf)
            End(-1);
        cout << res << '\n';
        auto ans = Max_Flow::get_ans();
        for (auto &x : ans)
            x = ((x + 2 * n - 1) % (2 * n) + 1) / 2;
        sort(ans.begin(), ans.end());
        for (int x : ans)
            cout << x << ' ';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
