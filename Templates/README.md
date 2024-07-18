- [AC自动机](#ac自动机)
- [欧拉筛](#欧拉筛)
- [FFT](#fft)
- [NTT](#ntt)
- [线段树合并/分裂](#线段树合并分裂)
- [莫队](#莫队)
- [树链剖分](#树链剖分)
- [二分图最大匹配](#二分图最大匹配)
- [最大流](#最大流)
- [最小费用最大流](#最小费用最大流)

## AC自动机
```cpp
struct AC_Automaton
{
    struct Trie
    {
        struct Node
        {
            vector<int> nxt;
            vector<int> res;
            int fail, mark;
            Node()
            {
                nxt.resize(26);
                fail = mark = 0;
            }
        };
        vector<Node> Nodes;
        Trie() { Nodes.resize(1); }
        int Add_Node()
        {
            int res = Nodes.size();
            Nodes.emplace_back();
            return res;
        }
        void Add_String(string s, int id)
        {
            int now = 0;
            for (auto c : s)
            {
                int &nxt = Nodes[now].nxt[c - 'a'];
                if (!nxt)
                    nxt = Add_Node();
                now = nxt;
            }
            Nodes[now].res.push_back(id);
        }
    } Tr;
    vector<int> inq;
    vector<int> cnt;
    void Build()
    {
        queue<int> Q;
        inq.resize(Tr.Nodes.size());
        cnt = inq;
        for (int i = 0; i < 26; ++i)
            if (Tr.Nodes[0].nxt[i])
                Q.push(Tr.Nodes[0].nxt[i]);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            auto &node = Tr.Nodes[u];
            for (int i = 0; i < 26; ++i)
            {
                int &p = node.nxt[i];
                int q = Tr.Nodes[node.fail].nxt[i];
                if (p)
                {
                    Tr.Nodes[p].fail = q;
                    ++inq[q];
                    Q.push(p);
                }
                else
                    p = q;
            }
        }
    }
    void Query(string s, vector<int> &ans)
    {
        int now = 0;
        for (auto c : s)
            ++cnt[now = Tr.Nodes[now].nxt[c - 'a']];
    }
    void Topo(vector<int> &ans)
    {
        queue<int> Q;
        for (int i = 1; i < inq.size(); ++i)
            if (!inq[i])
                Q.push(i);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            auto &node = Tr.Nodes[u];
            int v = node.fail;
            for (int id : node.res)
                ans[id] += cnt[u];
            cnt[v] += cnt[u];
            if (!--inq[v])
                Q.push(v);
        }
    }
} AC;

```

## 欧拉筛
```cpp
auto Pre(int n)
{
    vector<int> Pr;
    vector<int> P(n + 1); //欧拉函数
    for (int i = 2; i <= n; ++i)
    {
        if (!P[i])
            P[i] = i - 1, Pr.push_back(i);
        for (auto j : Pr)
        {
            ll now = 1ll * j * i;
            if (now > n)break;
            if (i % j == 0)
            {
                P[now] = j * P[i];
                break;
            }
            P[now] = P[i] * P[j];
        }
    }
}

```

## FFT
```cpp
namespace FFT
{
    const double pi = asin(1) * 2;
    struct Comp
    {
        double a, b;
        Comp(double _ = 0, double __ = 0) : a(_), b(__) {}
        Comp operator+(const Comp &_) const
        {
            return {a + _.a, b + _.b};
        }
        Comp operator-(const Comp &_) const
        {
            return {a - _.a, b - _.b};
        }
        Comp operator*(const Comp &_) const
        {
            return {a * _.a - b * _.b, a * _.b + b * _.a};
        }
    };
    void solve()
    {
        int l1 = rd(), l2 = rd(), len = 1, bit = 0;
        while (len <= l1 + l2)
            len <<= 1, ++bit;
        vector<int> idx(len);
        for (int i = 1; i < len; ++i)
            idx[i] = idx[i >> 1] >> 1 | (i & 1) << bit - 1;
        vector<Comp> A, B, C;
        for (int i = 0; i <= l1; ++i)
            A.push_back({rd(), 0});
        for (int i = 0; i <= l2; ++i)
            B.push_back({rd(), 0});
        A.resize(len), B.resize(len);
        auto FFT = [&](auto self, vector<Comp> &T, int p) -> void
        {
            int n = T.size(), m = n >> 1;
            if (n == 1)
                return;
            vector<Comp> X, Y;
            for (int i = 0; i < n; i += 2)
                X.push_back(T[i]), Y.push_back(T[i | 1]);
            self(self, X, p);
            self(self, Y, p);
            Comp W0(cos(2 * pi / n), sin(2 * pi / n) * p), W(1, 0);
            for (int i = 0; i < m; ++i, W = W * W0)
                T[i] = X[i] + W * Y[i], T[i + m] = X[i] - W * Y[i];
        };
        auto FFT_ = [&](vector<Comp> &T, int p) -> void
        {
            int len = T.size();
            for (int i = 0; i < len; ++i)
                if (i < idx[i])
                    swap(T[i], T[idx[i]]);
            for (int m = 1; m < len; m <<= 1)
            {
                int n = m << 1;
                Comp W0(cos(2 * pi / n), sin(2 * pi / n) * p);
                for (int j = 0; j < len; j += n)
                {
                    Comp W(1, 0);
                    for (int i = j; i < j + m; ++i, W = W * W0)
                    {
                        Comp X = T[i], Y = W * T[i + m];
                        T[i] = X + Y, T[i + m] = X - Y;
                    }
                }
            }
        };
        FFT_(A, 1);
        FFT_(B, 1);
        for (int i = 0; i < len; ++i)
            C.push_back(A[i] * B[i]);
        FFT_(C, -1);
        for (int i = 0; i <= l1 + l2; ++i)
            printf("%d%c", int(C[i].a / len + 0.5), " \n"[i == l1 + l2]);
    }
}

```

## NTT
```cpp
namespace NTT
{
    const int P = 998244353;
    int Qpow(int x, int n)
    {
        int res = 1;
        for (; n; n >>= 1, x = 1ll * x * x % P)
            if (n & 1)
                res = 1ll * x * res % P;
        return res;
    }
    const int G = 114514, G_ = Qpow(G, P - 2);
    void Solve()
    {
        int n = rd(), m = rd();
        int T = 1, bit = 0;
        while (T <= n + m)
            T <<= 1, ++bit;
        vector<int> idx(T);
        for (int i = 1; i < T; ++i)
            idx[i] = idx[i >> 1] >> 1 | (i & 1) << bit - 1;
        vector<int> A, B, C;
        for (int i = 0; i <= n; ++i)
            A.push_back(rd());
        for (int i = 0; i <= m; ++i)
            B.push_back(rd());
        A.resize(T);
        B.resize(T);
        auto NTT = [&](vector<int> &T, int g)
        {
            int len = T.size();
            for (int i = 0; i < len; ++i)
                if (i < idx[i])
                    swap(T[i], T[idx[i]]);
            for (int p = 1, m = 1; m < len; ++p, m <<= 1)
            {
                int W0 = Qpow(g, (P - 1) >> p);
                for (int i = 0; i + m < len; i += m << 1)
                {
                    int W = 1;
                    for (int j = i; j < i + m; ++j, W = 1ll * W * W0 % P)
                    {
                        int X = T[j], Y = 1ll * W * T[j + m] % P;
                        T[j] = (X + Y) % P;
                        T[j + m] = (0ll + X - Y + P) % P;
                    }
                }
            }
        };
        NTT(A, G);
        NTT(B, G);
        for (int i = 0; i < T; ++i)
            C.push_back(1ll * A[i] * B[i] % P);
        NTT(C, G_);
        int inv = Qpow(T, P - 2);
        for (int i = 0; i <= n + m; ++i)
            printf("%lld ", 1ll * C[i] * inv % P);
    }
}

```
## 线段树合并/分裂
```cpp
inline void Push_Up(int p)
{
    T[p] = T[ls[p]] + T[rs[p]];
}
void Upd(int &p, int x, int y, int L = 1, int R = n)
{
    if (!p)
        p = ++id;
    if (L == R)
    {
        T[p] += y;
        return;
    }
    int mid = L + R >> 1;
    if (x <= mid)
        Upd(ls[p], x, y, L, mid);
    else
        Upd(rs[p], x, y, mid + 1, R);
    Push_Up(p);
}
void Merge(int &p, int q, int L = 1, int R = n)
{
    if (!q)
        return;
    if (!p)
    {
        p = q;
        return;
    }
    if (L == R)
    {
        T[p] += T[q];
        return;
    }
    int mid = L + R >> 1;
    Merge(ls[p], ls[q], L, mid);
    Merge(rs[p], rs[q], mid + 1, R);
    Push_Up(p);
}
void Split(int &p, int &q, int l, int r, int L = 1, int R = n)
{
    if (!p)
        return;
    if (l == L and r == R)
    {
        q = p;
        p = 0;
        return;
    }
    if (!q)
        q = ++id;
    int mid = L + R >> 1;
    if (r <= mid)
        Split(ls[p], ls[q], l, r, L, mid);
    else if (l > mid)
        Split(rs[p], rs[q], l, r, mid + 1, R);
    else
        Split(ls[p], ls[q], l, mid, L, mid), Split(rs[p], rs[q], mid + 1, r, mid + 1, R);
    Push_Up(p);
    Push_Up(q);
}
ll Query(int p, int l, int r, int L = 1, int R = n)
{
    if (!p)
        return 0;
    if (l == L and r == R)
        return T[p];
    int mid = L + R >> 1;
    if (r <= mid)
        return Query(ls[p], l, r, L, mid);
    if (l > mid)
        return Query(rs[p], l, r, mid + 1, R);
    return Query(ls[p], l, mid, L, mid) + Query(rs[p], mid + 1, r, mid + 1, R);
}
int Kth(int p, ll k, int L = 1, int R = n)
{
    if (L == R)
        return L;
    int mid = L + R >> 1;
    ll m = T[ls[p]];
    if (k <= m)
        return Kth(ls[p], k, L, mid);
    else
        return Kth(rs[p], k - m, mid + 1, R);
}

```
## 莫队
```cpp
namespace Mo_Team
{
    const int N = 5e4 + 5;
    int n, m, k, sz;
    int A[N], cnt[N];
    ll ans, res[N];
    struct Query
    {
        int l, r, id;
        int pl, pr;
        void input(int i)
        {
            cin >> l >> r;
            id = i;
            pl = (l - 1) / sz + 1;
            pr = (r - 1) / sz + 1;
        }
        bool operator<(const Query &_) const
        {
            if (pl == _.pl)
            {
                if (pr == _.pr)
                    return r < _.r;
                return pr < _.pr;
            }
            return pl < _.pl;
        }
    } Q[N];
    void Add(int t)
    {
        ans += cnt[t] * 2 + 1;
        ++cnt[t];
    }
    void Del(int t)
    {
        ans -= cnt[t] * 2 - 1;
        --cnt[t];
    }
    void solve()
    {
        cin >> n >> m >> k;
        sz = sqrt(n) + 1;
        for (int i = 1; i <= n; ++i)
            cin >> A[i];
        for (int i = 1; i <= m; ++i)
            Q[i].input(i);
        sort(Q + 1, Q + m + 1);
        int l = 1, r = 0;
        for (int i = 1; i <= m; ++i)
        {
            int L = Q[i].l, R = Q[i].r;
            while (l > L)
                Add(A[--l]);
            while (r < R)
                Add(A[++r]);
            while (l < L)
                Del(A[l++]);
            while (r > R)
                Del(A[r--]);
            res[Q[i].id] = ans;
        }
        for (int i = 1; i <= m; ++i)
            cout << res[i] << "\n";
    }
}

```

## 树链剖分
```cpp
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
```
## 二分图最大匹配
```cpp
bool dfs(int u)
{
    for (auto v : E[u])
        if (!vis[v] && (vis[v] = 1) && (!match[v] || dfs(match[v])))
            return match[v] = u;
}

```
## 最大流
```cpp
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
```
## 最小费用最大流
```cpp
namespace Max_Flow_Min_Cost
{
    const int N = 5e5 + 5;
    const int M = 3e6 + 5;
    const ll inf = 1e18;
    int n, m, S, T;
    int tot = 1, head[N], nxt[M], V[M], W[M], C[M];
    int pre[N], preid[N];
    ll flow[N], dis[N];
    bool vis[N];
    void Add(int u, int v, int w, int c)
    {
        nxt[++tot] = head[u];
        V[head[u] = tot] = v;
        W[tot] = w;
        C[tot] = c;
    }
    bool BFS()
    {
        queue<int> Q;
        for (int i = 1; i <= n; ++i)
            flow[i] = 0, dis[i] = inf, vis[i] = 0;
        flow[S] = inf, dis[S] = 0, vis[S] = 1;
        Q.push(S);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = V[i], w = W[i], c = C[i];
                if (w == 0)
                    continue;
                if (dis[v] <= dis[u] + c)
                    continue;
                dis[v] = dis[u] + c;
                flow[v] = min(flow[u], 0ll + w);
                pre[v] = u;
                preid[v] = i;
                if (!vis[v])
                    vis[v] = 1, Q.push(v);
            }
        }
        if (flow[T] == 0)
            return 0;
        if (dis[T] == inf)
            return 0;
        return 1;
    }
    void max_flow()
    {
        ll res = 0, cost = 0;
        while (BFS())
        {
            int u = T;
            while (u != S)
            {
                int id = preid[u];
                W[id] -= flow[T];
                W[id ^ 1] += flow[T];
                u = V[id ^ 1];
            }
            res += flow[T];
            cost += flow[T] * dis[T];
        }
        cout << res << ' ' << cost << '\n';
    }
    void solve()
    {
        cin >> n >> m >> S >> T;
        for (int i = 1; i <= m; ++i)
        {
            int u, v, w, c;
            cin >> u >> v >> w >> c;
            Add(u, v, w, c);
            Add(v, u, 0, -c);
        }
        max_flow();
    }
}
```
