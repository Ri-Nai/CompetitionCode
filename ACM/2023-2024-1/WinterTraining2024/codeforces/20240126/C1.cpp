#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=2e5+5;
    int in[N];
    int dfn[N],low[N],stk[N],num,top,blk,blg[N],sz[N];
    bool vis[N],ans=1;
    vector<int>E[N],P[N];
    void Tarjan(int u,int f)
    {
        dfn[stk[++top]=u]=low[u]=++num;
        for(int v:E[u])
        {
            if(v==f)continue;
            if(!dfn[v])Tarjan(v,u),low[u]=min(low[v],low[u]);
            else low[u]=min(low[u],dfn[v]);
        }
        if(low[u]==dfn[u])
        {
            int v;++blk;
            do ++sz[blg[v=stk[top--]]=blk];while(u!=v);
        }
    }
    map<pair<int,int>,int>mp;
    bool dfs(int u,int f)
    {
        vis[u]=1;
        bool flag=sz[u]>1;
        for(int v:P[u])
            if(!vis[v])
            {
                bool t=dfs(v,u);
                if(mp[{v,u}])flag|=t;
            }
        return flag;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            int u,v;
            cin>>u>>v;
            E[u].push_back(v);
            ++in[v];
        }
        for(int i=1;i<=n;++i)if(!in[i])End("NO");
        for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i,0);
        for(int i=1;i<=blk;++i)in[i]=0;
        // for(int i=1;i<=n;++i)cout<<blg[i]<<" \n"[i==n];
        for(int i=1;i<=n;++i)
            for(int v:E[i])if(blg[i]^blg[v])
            {
                int x=blg[i],y=blg[v];
                // if(x>y)swap(x,y);
                if(!mp[{x,y}] && !mp[{y,x}])
                    P[blg[i]].push_back(blg[v]),++in[blg[v]];
                mp[{x,y}]=1;
            }

        for(int i=1;i<=blk;++i)if(!in[i])ans&=dfs(i,0);
        if(ans)End("YES");
        else End("NO");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
