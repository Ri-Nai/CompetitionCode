#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
ll rd()
{
    ll res = 0, f = 1;
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
        int n = rd();
        ll ans = 0;
        vector<ll> A(n + 1);
        vector<vector<int>>E(n + 1);
        for (int i = 1; i <= n; ++i)
            ans += (A[i] = rd());
        for (int i = 1; i < n; ++i)
        {
            int u = rd(), v = rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        const ll inf = 1e18;
        vector<ll>dp1(n + 1, inf), dp2(n + 1, inf);
        vector<int>is(n + 1);
        auto dfs = [&](auto self, int u, int f) -> void
        {
            int in = 0;
            for (int v : E[u]) if (v != f)
                ++in, self(self, v, u);
            vector<ll> val(in + 2);
            ll sum = 0;
            for (int v : E[u]) if (v != f)
            {
                sum += dp1[v];
                if (is[v] < in + 2)
                    val[is[v]] += dp2[v] - dp1[v];
            }
            for (int i = 0; i < in + 2; ++i)
            {
                ll now = sum + val[i];
                if (now < dp1[u])
                {
                    dp2[u] = dp1[u];
                    dp1[u] = now;
                    is[u] = i;
                }
                else if (now < dp2[u])
                    dp2[u] = now;
                sum += A[u];
            }
        };
        dfs(dfs, 1, 0);
        cout << ans + dp1[1] << '\n';
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
