#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout << X << '\n', void()
bool Nai;
namespace T
{
    const int N = 6e5 + 5;
    struct Pr
    {
        int v, w;
    };
    vector<Pr> E[N];
    int n, S;
    ll dp[N], ans;
    void dfs(int u, int f)
    {
        for (Pr t : E[u])
        {
            int v = t.v, w = t.w;
            if (v == f)
                continue;
            dfs(v, u);
            dp[u] = max(dp[u], w + dp[v]);
        }
        for (Pr t : E[u])
        {
            int v = t.v, w = t.w;
            if (v == f)
                continue;
            ans += dp[u] - (w + dp[v]);
        }
    }
    void solve()
    {
        cin >> n >> S;
        for (int i = 1, u, v, w; i < n; ++i)
            cin >> u >> v >> w,
                E[v].push_back((Pr){u, w}),
                E[u].push_back((Pr){v, w});
        dfs(S, S);
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();
}
