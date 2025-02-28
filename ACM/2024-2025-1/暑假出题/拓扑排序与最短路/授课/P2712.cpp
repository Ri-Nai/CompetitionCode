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
        int n = rd(), m = 500;
        vector<int> in(m + 1), cnt(m + 1);
        vector<vector<int>> E(m + 1);
        for (int i = 1; i <= n; ++i)
        {
            int u = rd(), m = rd();
            ++cnt[u];
            while (m--)
            {
                int v = rd();
                E[u].push_back(v);
                ++in[v];
            }
        }
        queue<int> Q;
        for (int i = 1; i <= m; ++i)
            if (!in[i])
                Q.push(i);
        int ans = 0;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            ans += cnt[u];
            for (int v : E[u])
                if (!--in[v])
                    Q.push(v);
        }
        if (ans == n)
            puts("YES");
        else cout << n - ans << '\n';
        vector<int> color(n + 1);
        vector<vector<int>> has(n + 1);
        auto dfs = [&](auto self, int u, int c) -> void
        {
            if (color[u] || !in[u])
                return;
            color[u] = c;
            has[c].push_back(u);
            for (int v : E[u])
                self(self, v, c);
        };
        int num = 0;
        for (int i = 1; i <= n; ++i)
            if (in[i] && !color[i])
                dfs(dfs, i, ++num);
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
