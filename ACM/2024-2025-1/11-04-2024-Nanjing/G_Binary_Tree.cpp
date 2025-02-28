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
namespace T
{
    void solve()
    {
        int n;
        scanf("%d", &n);
        vector<vector<int>> edge(n + 1);
        auto addEdge = [&](int x, int y)
        {
            edge[x].push_back(y);
            edge[y].push_back(x);
        };
        for (int i = 1; i <= n; ++i)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l)
                addEdge(i, l);
            if (r)
                addEdge(i, r);
        }
        vector<int> mark(n + 1);
        int rt = 1;
        auto ask = [&](int u, int v)
        {
            cout << "? " << u << " " << v << endl;
            int res;
            cin >> res;
            return res;
        };
        auto confirm = [&](int x)
        {
            cout << "! " << x << endl;
            return true;
        };
        auto running = [&]()
        {
            vector<int> ind(n + 1);
            vector<int> sz(n + 1, 1);
            vector<int> mxsz(n + 1);
            int heavy = 0;
            mxsz[0] = n + n;
            int total = 0;
            auto dfs = [&](auto &&self, int u, int f) -> void
            {
                ++total;
                for (int v : edge[u])
                {
                    ++ind[v];
                    if (mark[v] || v == f)
                        continue;
                    self(self, v, u);
                    sz[u] += sz[v];
                }
            };
            auto getHeavy = [&](auto &&self, int u, int f) -> void
            {
                mxsz[u] = total - sz[u];
                for (int v : edge[u])
                {
                    if (mark[v] || v == f)
                        continue;
                    self(self, v, u);
                    mxsz[u] = max(mxsz[u], sz[v]);
                }
                if (mxsz[u] < mxsz[heavy])
                    heavy = u;
            };
            dfs(dfs, rt, rt);
            getHeavy(getHeavy, rt, rt);
            rt = heavy;
            if (ind[rt] == 0)
                return confirm(rt);
            if (ind[rt] == 1)
            {
                for (int v : edge[rt])
                    if (!mark[v])
                    {
                        if (ask(rt, v) == 0)
                            return confirm(rt);
                        return confirm(v);
                    }
            }
            ind.assign(n + 1, 0);
            sz.assign(n + 1, 1);
            dfs(dfs, rt, rt);
            vector<int> nodes;
            for (int v : edge[rt])
                if (!mark[v])
                    nodes.push_back(v);
            sort(nodes.begin(), nodes.end(), [&](int a, int b)
                 { return sz[a] > sz[b]; });

            int res = ask(nodes[0], nodes[1]);
            if (res == 1)
                mark[nodes[0]] = mark[nodes[1]] = 1;
            else
            {
                mark[rt] = 1;
                mark[nodes[(res >> 1) ^ 1]] = 1;
                rt = nodes[res >> 1];
            }
            return false;
        };
        while (!running())
            ;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
