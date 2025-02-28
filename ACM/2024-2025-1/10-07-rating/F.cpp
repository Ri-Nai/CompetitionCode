#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> fa(n + 1), A(n + 1), dp(n + 1), work(n + 1);
    vector<vector<int>> E(n + 1);
    for (int i = 2; i <= n; ++i)
        scanf("%d", &fa[i]), E[fa[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    int ans = 0;
    auto dfs = [&](auto &&self, int u) -> void
    {
        // dp[u] = A[u];
        for (int v : E[u])
        {
            self(self, v);
            dp[u] += dp[v];
        }
        if (dp[u] + A[u] & 1)
            ++dp[u], work[u] = 1;
    };
    dfs(dfs, 1);
    ans = dp[1];
    int Q;
    cin >> Q;
    while (Q--)
    {
        int x;
        scanf("%d", &x);
        A[x] ^= 1;
        if (work[x] == 0)
            ++ans;
        else
            --ans;
        work[x] ^= 1;
        if (x != 1)
        {
            x = fa[x];
            if (work[x] == 0)
                ++ans;
            else
                --ans;
            work[x] ^= 1;
        }
        cout << ans << '\n';
    }
}
