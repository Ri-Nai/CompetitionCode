#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=2e5+5;
    bool mark[N][3];
    int dis[N][3],n,m;
    int V[N],tot,head[N],W[N],nxt[N],L[N],R[N];
    void Add(int u,int v,int w,int l,int r)
    {
        nxt[++tot]=head[u];
        V[head[u]=tot]=v;
        W[tot]=w;L[tot]=l,R[tot]=r;
    }
    struct Pr
    {
        int x,val,time;
        bool operator <(const Pr & P)const
        {
            return time==P.time?val>P.val:time>P.time;
        }
    };
    void dijkstra()
    {
        priority_queue<Pr> Q;
        Q.push((Pr){1,0,0});
        while(!Q.empty())
        {
            Pr P=Q.top();
            Q.pop();
            int u=P.x,t=P.time,val=P.val;
            // cout<<u<<'\n';
            if(mark[u][t])continue;
            mark[u][t]=1;
            // cout<<u<<' '<<t<<' '<<val<<'\n';
            for(int i=head[u];i;i=nxt[i])
            {
                int v=V[i],w=W[i],l=L[i],r=R[i];
                int now=w+val;
                if(val>=l and val<r)now=r+w;
                // cout<<i<<' '<<nxt[i]<<'\n';
                // cout<<u<<' '<<v<<' '<<l<<' '<<r<<' '<<w<<'\n';
                // cout<<now<<'\n';
                // cout<<"aaa"<<tt<<'\n';
                if(t+1<=2 and dis[v][t+1]>val)
                    dis[v][t+1]=val,Q.push((Pr){v,val,t+1});
                if(dis[v][t]>now)
                    dis[v][t]=now,Q.push((Pr){v,now,t});
            }
        }
        // cout<<n<<"\n";
        // cout<<dis[n][1]<<' '<<dis[n][2]<<' '<<dis[n][0]<<'\n';
        cout<<min(min(dis[n][0],dis[n][1]),dis[n][2])<<'\n';
    }
    void solve()
    {
        cin>>n>>m;
        memset(dis,0x3f,sizeof dis);
        dis[1][0]=0;
        dis[1][1]=0;
        dis[1][2]=0;
        for(int i=1;i<=m;++i)
        {
            int u,v,w,l,r;
            cin>>u>>v>>w>>l>>r;
            // cout<<u<<' '<<v<<' '<<l<<' '<<r<<' '<<w<<'\n';
            Add(u,v,w,l,r);
            Add(v,u,w,l,r);
        }
        dijkstra();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
