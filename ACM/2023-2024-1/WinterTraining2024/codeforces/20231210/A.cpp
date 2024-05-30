#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,mod=1e9+7;
typedef long long ll;
ll dp[N][N],ans[N];
int n,k,sz[N];
vector<int>E[N];
void dfs(int u,int f)
{
    dp[u][1]=1;
    sz[u]=1;
    for(int v:E[u])
    {
        if(v==f)continue;
        dfs(v,u);
    }
    for(int v:E[u])
    {
        if(v==f)continue;
        sz[u]+=sz[v];
        for(int i=sz[u];i>=1;--i)
            for(int j=1;j<=min(sz[v],i);++j)
                dp[u][i]=(dp[u][i]+dp[v][j]*dp[u][i-j]%mod)%mod;
    }
    for(int i=1;i<=n;++i)ans[i]=(ans[i]+dp[u][i])%mod;
}
void Solve()
{
    cin>>n;
    for(int x,i=2;i<=n;++i)
    {
        cin>>x;++x;
        E[x].push_back(i);
        E[i].push_back(x);
    }
    dfs(1,1);
    for(int i=1;i<=n;++i)cout<<ans[i]<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
/*
a-b=1  -1
b-a=1  -1
*/
