#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=205;
    const int M=1e4+5;
    int n,m,S,T;
    int tot=1,head[N],nxt[M],V[M],W[M];
    bool vis[N];
    void Add(int u,int v,int w)
    {
        nxt[++tot]=head[u];
        V[head[u]=tot]=v;
        W[tot]=w;
    }
    ll dfs(int u,int f)
    {
        if(u==T)return f;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=V[i],w=W[i];
            if(w==0)continue;
            if(vis[v])continue;
            int now=dfs(v,min(f,w));
            if(now==0)continue;
            W[i]-=now;
            W[i^1]+=now;
            return now;
        }
        return 0;
    }
    ll max_flow()
    {
        ll res=0,now=0;
        while(now=dfs(S,1e9))
            memset(vis,0,sizeof vis),res+=now;
        return res;
    }
    void solve()
    {
        cin>>n>>m>>S>>T;
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            Add(u,v,w);
            Add(v,u,0);
        }
        cout<<max_flow()<<'\n';
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
