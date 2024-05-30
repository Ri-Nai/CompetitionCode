#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int rd()
    {
        int res=0,f=1;char c;
        do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
        while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
        return res*f;
    }
    void solve()
    {
        const int mod=998244353;
        int n=rd(),m=rd();
        vector<vector<int>>E(n+1);
        vector<int>dep(n+1,0);
        for(int i=1;i<=m;++i)
        {
            int u=rd(),v=rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        auto dfs=[&](auto self,int u,int f)->void
        {
            dep[u]=dep[f]+1;
            for(int v:E[u])
                if(!dep[v])self(self,v,u);
        };
        auto Qpow=[&](int n,int p)
        {
            int res=1;
            for(int x=n;p;x=1ll*x*x%mod,p>>=1)
                if(p&1)res=1ll*res*x%mod;
            return res;
        };
        int res=1;
        for(int i=1;i<=n;++i)
        {
            if(dep[i])continue;
            dfs(dfs,i,0);
            vector<int>ans(2,0);
            auto dfs_=[&](auto self,int u)->void
            {
                for(int v:E[u])
                {
                    if(dep[v]==dep[u]+1)self(self,v);
                    if(dep[v]<dep[u]-1)++ans[dep[u]-dep[v]&1];
                }
            };
            dfs_(dfs_,i);
            int now=max(ans[0]-1,0)+ans[1];
            res=1ll*res*Qpow(5,now)%mod;
        }
        cout<<res<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
