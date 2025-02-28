#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    typedef bitset<255> ull;
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> id(n + 1), dep(n + 1), fa(n + 1), sz(n + 1), son(n + 1), top(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        dep[u] = dep[fa[u] = f] + 1;
        for (int v : edge[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]])
                son[u] = v;
        }
    };
    int tot = 0;
    auto dfs_ = [&](auto &&self, int u, int tp) -> void
    {
        top[u] = tp;
        id[u] = ++tot;
        if (son[u])
            self(self, son[u], tp);
        for (int v : edge[u])
            if (v != son[u] && v != fa[u])
                self(self, v, v);      
    };
    dfs(dfs, 1, 0);
    dfs_(dfs_, 1, 1);
    auto getPath = [&](int x, int y) -> vector<int>
    {
        auto LCA = [&](int u, int v)
        {
            while (top[u] != top[v])
            {
                if (dep[top[u]] >= dep[top[v]])
                    u = fa[top[u]];
                else 
                    v = fa[top[v]];
            }
            if (dep[u] <= dep[v])
                return u;
            else 
                return v;
        };
        int f = LCA(x, y);
        int length = dep[x] + dep[y] - dep[f] - dep[f];
        if (length != k)
            return {};
        vector<int> ans;
        while (x != f)
            ans.push_back(x), x = fa[x];
        while (y != f)
            ans.push_back(y), y = fa[y];
        ans.push_back(f);
        return ans;
    };
    struct Path
    {
        int u, v;
        ull mask;
    };

    vector<Path> paths;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            auto path = getPath(i, j);
            if (path.empty())
                continue;
            ull mask;
            for (auto x : path)
                mask.set(x);
            mask >>= 2;
            paths.push_back({i, j, mask});
        }

    struct LinearBase
    {
        vector<ull> base;
        vector<int> vis;
        vector<int> id;
        int n;
        LinearBase(int n) : n(n)
        {
            base.resize(n);
            vis.resize(n);
        }
        void insert(ull mask, int idx)
        {
            for (int i = n - 2; i >= 0; --i)
                if (mask[i])
                {
                    if (vis[i])
                        mask ^= base[i];
                    else
                    {
                        base[i] = mask;
                        vis[i] = 1;
                        id.push_back(idx);
                        break;
                    }
                }
        }
    }l(n);

    for (int i = 0; i < paths.size(); ++i)
    {
        auto p = paths[i];
        l.insert(p.mask, i);      
    }

    if (l.id.size() < n - 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    assert(l.id.size() == n - 1);
    auto ids = l.id;

    cout << "YES" << endl;
    cout << "? " << ids.size();
    for (auto x : ids)
        cout << " " << paths[x].u << " " << paths[x].v;
    cout << endl;
    vector<vector<int>> mat(n - 1, vector<int>(n));
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
            mat[i][j] = paths[ids[i]].mask[j];
        cin >> mat[i][n - 1];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
            if (mat[j][i] >= mat[i][i])
                swap(mat[j], mat[i]);
        for (int j = i + 1; j < n - 1; ++j)
        {
            if (mat[j][i])
                for (int k = i; k < n; ++k)
                    mat[j][k] ^= mat[i][k];
        }
    }
    for (int i = n - 2; i >= 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (mat[j][i])
                mat[j][i] ^= 1, mat[j][n - 1] ^= mat[i][n - 1];
    cout << "!";
    for (int i = 0; i < n - 1; ++i) 
        cout << " " << mat[i][n - 1];
    cout << endl;
}
