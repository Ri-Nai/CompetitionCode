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
        vector<vector<int>>E(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int>color(n + 1, -1);
        bool ring = 0;
        stack<int>stk;
        auto dfs = [&](auto self, int u, int f, int now) -> void
        {
            if (ring) return;
            if (~color[u])
            {
                vector<int> ans;
                if (color[u] == now)
                    return;
                while (stk.top() != u)
                    ans.push_back(stk.top()), stk.pop();
                ans.push_back(u);
                printf("%d\n", ans.size());
                for (int i = 0; i < ans.size(); ++i)
                    printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
                ring = 1;
            }
            stk.push(u);
            color[u] = now;
            for (int v : E[u])
                self(self, v, u, now ^ 1);
            if(!ring)stk.pop();
        };
        dfs(dfs, 1, -1, 0);
        if (!ring)
        {
            puts("0");
            for (int i = 1; i <= n; ++i)
                printf("%d%c", color[i], " \n"[i == n]);
        }
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
