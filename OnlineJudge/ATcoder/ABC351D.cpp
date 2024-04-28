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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> Map;
        for (int i = 0; i < n; ++i)
        {
            Map.emplace_back();
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j)
                Map[i].push_back(s[j] == '#');
        }
        vector<int> fa(n * m);
        vector<int> sz(n * m);
        vector<set<int>> has(n * m);
        auto get_id = [&](int x, int y)
        {
            return x * m + y;
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int id = get_id(i, j);
                fa[id] = id;
                sz[id] = 1;
            }
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        auto is_in = [&](int x, int y)
        {
            return !(x < 0 || y < 0 || x >= n || y >= m);
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (Map[i][j] == 1)
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if (!is_in(x, y))
                        continue;
                    if (Map[x][y] == 1)
                        Map[i][j] = 2;
                }
            }
        int ans = 1;
        auto find = [&](int u)
        {
            while (u != fa[u])
            {
                fa[u] = fa[fa[u]];
                u = fa[u];
            }
            return u;
        };
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (Map[i][j])
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if (!is_in(x, y))
                        continue;
                    if (Map[x][y])
                    {
                        if (Map[x][y] == 2)
                            has[find(get_id(i, j))].insert(get_id(x, y));
                        continue;
                    }
                    int u = get_id(i, j);
                    int v = get_id(x, y);
                    int fu = find(u);
                    int fv = find(v);
                    if (fu == fv)continue;
                    if (has[fu].size() < has[fv].size())
                        swap(fu, fv);
                    fa[fv] = fu;
                    sz[fu] += sz[fv];
                    for (auto x : has[fv])
                        has[fu].insert(x);
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int id = get_id(i, j);
                ans = max(ans, sz[id] + (int)has[id].size());
            }
        cout <<ans << '\n';
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
