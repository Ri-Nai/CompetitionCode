#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m,k;
    const int N=3e5+5,mod=1e9+7;
    vector<int>E[N];
    int fa[N][20],d[N],cnt[N],dep[N];
    int fac[N],inv[N];
    int ans;
    int C(int n,int m)
    {
        if(m>n)return 0;
        return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    int pow(int x,int p)
    {
        int res=1;
        for(;p;p>>=1)
        {
            if(p&1)res=1ll*x*res%mod;
            x=1ll*x*x%mod;
        }
        return res;
    }
    void dfs(int u,int f)
    {
        fa[u][0]=f;
        for(int v:E[u])
        {
            if(v==f)continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
    }
    int LCA(int u,int v)
    {
        if(dep[v]>dep[u])swap(u,v);
        int t=dep[u]-dep[v];
        // cout<<u<<' '<<v<<'\n';
        // cout<<t<<'\n';
        for(int i=0;t&&i<=19;++i)
            if(t&(1<<i))t^=1<<i,u=fa[u][i];
        // cout<<u<<' '<<v<<'\n';
        // cout<<"*************\n";
        if(u==v)return u;
        for(int i=19;i>=0;--i)
            if(fa[u][i]^fa[v][i])
                u=fa[u][i],v=fa[v][i];
        return fa[u][0];
    }
    void dfs_(int u,int f)
    {
        for(int v:E[u])
        {
            if(v==f)continue;
            dfs_(v,u);
            d[u]+=d[v];
        }
        ans=(0ll+mod+ans+C(d[u],k)-C(d[u]-cnt[u],k))%mod;
    }
    void pre()
    {
        fac[0]=1;
        for(int i=1;i<N;++i)
            fac[i]=1ll*fac[i-1]*i%mod;
        inv[N-1]=pow(fac[N-1],mod-2);
        for(int i=N-2;~i;--i)
            inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    void solve()
    {
        ans=0;
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i)d[i]=0,cnt[i]=0,E[i].clear();
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=19;++i)
            for(int j=1;j<=n;++j)
                fa[j][i]=fa[fa[j][i-1]][i-1];
        for(int i=1;i<=m;++i)
        {
            int u,v;
            cin>>u>>v;
            int f=LCA(u,v);
            ++d[u];++d[v];--d[f];
            --d[fa[f][0]];++cnt[f];
        }
        dfs_(1,0);
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    T::pre();
    int t;cin>>t;while(t--)
    T::solve();

}
