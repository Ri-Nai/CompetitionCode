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
        int n = rd(), m = rd();
        vector<vector<int>> E(n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> vis(n + 1, -1);
        vector<vector<vector<int>>> has(2);
        for (int i = 1; i <= n; ++i)
            if (vis[i] == -1)
            {
                // cout << i << '\n';
                has[0].emplace_back();
                has[1].emplace_back();
                auto dfs = [&](auto self, int u, int f, int dep) -> void
                {
                    vis[u] = dep;
                    int col = has[dep].size() - 1;
                    has[dep][col].push_back(u);
                    for (int v : E[u])
                    {
                        if (v == f)
                            continue;
                        self(self, v, u, dep ^ 1);
                    }
                };
                dfs(dfs, i, 0, 0);
            }

        vector<int> ans;
        if (m == n - 1)
        {
            int keyu = -1, keyv = -1;
            if (has[0][0].size() == 1 || has[1][0].size() == 1)
                End("-1");
            for (int i = 1; i <= n; ++i)
                if (E[i].size() == 1)
                {
                    keyu = i;
                    for (int j = 1; keyv == -1 && j <= n; ++j)
                        if (vis[j] ^ vis[i])
                            if (j != E[i][0])
                                keyv = j;
                    if (vis[i])
                        swap(keyu, keyv);
                    break;
                }
            for (int u : has[0][0])
                if (u != keyu)
                    ans.push_back(u);
            ans.push_back(keyu);
            ans.push_back(keyv);
            for (int v : has[1][0])
                if (v != keyv)
                    ans.push_back(v);
            for (int u : ans)
                cout << u << ' ';
            cout << '\n';
            return;
        }
        int col = has[0].size();
        vector<int> one, id;
        for (int i = 0; i < col; ++i)
            if (has[1][i].size() == 0)
                one.push_back(has[0][i][0]);
            else
                id.push_back(i);
        for (int i = 0; i < id.size(); ++i)
        {
            int now = id[i];
            for (int v : has[i & 1][now])
                ans.push_back(v);
        }
        for (int v : one)
            ans.push_back(v);
        for (int i = 0; i < id.size(); ++i)
        {
            int now = id[i];
            for (int v : has[i & 1 ^ 1][now])
                ans.push_back(v);
        }
        for (int u : ans)
            cout << u << ' ';
        cout << '\n';
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
