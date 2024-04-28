#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=1e3+5,M=1e5+5,inf=0x3f3f3f3f;
    int n,m,s,in[N],vis[N],dis[N],can[N];
    int head[N],tot,to[M],val[M],nxt[M];
    void Add(int u,int v,int w)
    {
        nxt[++tot]=head[u];
        to[head[u]=tot]=v;
        val[tot]=w;
    }
    void solve()
    {
        cin>>n>>m>>s;
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            Add(u,v,w);
        }
        memset(dis,inf,sizeof dis);
        dis[s]=0;can[s]=1;
        queue<int>q;
        for(int i=1;i<=n;++i)
            q.push(i),vis[i]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=head[u];i;i=nxt[i])
            {
                int v=to[i],w=val[i];
                ++in[v];
                can[v]|=can[u];
                if(in[v]>n)End(-1);
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    if(!vis[v])vis[v]=1,q.push(v);
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(!can[i])cout<<"NoPath\n";
            else cout<<dis[i]<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
