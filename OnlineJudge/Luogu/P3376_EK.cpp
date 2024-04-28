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
    int flow[N],pre[N],preid[N];
    void Add(int u,int v,int w)
    {
        nxt[++tot]=head[u];
        V[head[u]=tot]=v;
        W[tot]=w;
    }
    bool BFS()
    {
        queue<int>Q;
        for(int i=1;i<=n;++i)flow[i]=0;
        flow[S]=1e9;
        Q.push(S);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            // cout<<u<<'\n';
            for(int i=head[u];i;i=nxt[i])
            {
                int v=V[i],w=W[i];
                if(w==0)continue;
                if(flow[v])continue;
                flow[v]=min(flow[u],w);
                pre[v]=u;
                preid[v]=i;
                Q.push(v);
                if(v==T)return 1;
            }
        }
        return 0;
    }
    ll max_flow()
    {
        ll res=0;
        while(BFS())
        {
            int u=T;
            // cout<<"*****\n";
            while(u!=S)
            {
                int id=preid[u];
                W[id]-=flow[T];
                W[id^1]+=flow[T];
                u=pre[u];
            }
            res+=flow[T];
            // cout<<flow[T]<<'\n';
        }
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
