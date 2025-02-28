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
        vector<set<int>> S(n);
        vector<int> X(n), Y(n);
        int limit = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = rd();
            vector<int> mark(l + 2);
            for (int j = 0, x; j < l; ++j)
                if ((x = rd()) < l + 2)
                    mark[x] = 1;
            int p = 0;
            for (p = 0; mark[p] && p < l + 2; ++p);
            X[i] = p;
            res = max(res, p);
            for (++p ;mark[p] && p < l + 2; ++p);
            Y[i] = p;
            limit = max(limit, p);
        }
        vector<vector<int>> E(limit + 1);
        for (int i = 0; i < n; ++i)
            E[X[i]].push_back(Y[i]);
        vector<int> dp(limit + 1, -1);
        int other = 0;
        auto dfs = [&](auto self, int x) -> int
        {
            if (~dp[x])
                return dp[x];
            dp[x] = max(res, x);
            for (auto y : E[x])
                dp[x] = max(dp[x], self(self, y));
            if (E[x].size() >= 2)
                other = max(other, dp[x]);
            return dp[x];
        };
        ll ans = 0;
        for (int i = 0; i <= limit; ++i)
            dfs(dfs, i);
        for (int i = 0; i <= min(m, limit); ++i)
            ans += max(other, dfs(dfs, i));
        ans += 1ll * max(m - limit, 0) * (limit + m + 1) / 2;
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
