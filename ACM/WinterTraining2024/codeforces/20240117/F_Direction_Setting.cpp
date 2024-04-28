#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=5000;
    const int M=1e4+5;
    int n,m,S,T;
    int tot=1,head[N],Now[N],nxt[M],V[M],W[M];
    int bfn[N];
    bool vis[N];
    int EU[N],EV[N],A[N];
    void Add(int u,int v,int w)
    {
        nxt[++tot]=head[u];
        V[head[u]=tot]=v;
        W[tot]=w;
    }
    void Addnet(int u,int v,int w)
    {
        Add(u,v,w);
        Add(v,u,0);
    }
    bool BFS()
    {
        queue<int>Q;
        Q.push(S);
        for(int i=0;i<=T;++i)
            vis[i]=0;
        vis[S]=1;
        bool flag=0;
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int i=head[u];i;i=nxt[i])
            {
                int v=V[i],w=W[i];
                if(w==0)continue;
                if(vis[v])continue;
                vis[v]=1;
                bfn[v]=bfn[u]+1;
                if(v==T)flag=1;
                Q.push(v);
            }
        }
        return flag;
    }
    int dfs(int u,int f)
    {
        if(u==T)return f;
        for(int i=Now[u];i;i=nxt[i])
        {
            int v=V[i],w=W[i];
            Now[u]=i;
            if(w==0)continue;
            if(bfn[v]!=bfn[u]+1)continue;
            int now=dfs(v,min(w,f));
            if(now==0)
            {
                bfn[v]=-1;
                continue;
            }
            W[i]-=now;
            W[i^1]+=now;
            return now;
        }
        return 0;
    }
    ll max_flow()
    {
        ll res=0;
        while(BFS())
        {
            int now=0;
            for(int i=0;i<=T;++i)Now[i]=head[i];
            while(now=dfs(S,1e9))res+=now;
        }
        return res;
    }
    void solve()
    {
        cin>>n>>m;
        tot=1;
        T=n+m+1;
        for(int i=0;i<=T;++i)head[i]=0;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=m;++i)
        {
            cin>>EU[i]>>EV[i];
            Addnet(0,i,1);
        }/*2~2m*/
        for(int i=1;i<=m;++i)
        {
            Addnet(i,m+EV[i],1);
            Addnet(i,m+EU[i],1);
        }//2m+2 6m
        for(int i=1;i<=n;++i)
            Addnet(m+i,T,A[i]);
        cout<<m-max_flow()<<'\n';
        int now=2*m+2;
        for(int i=1;i<=m;++i)
        {
            if(W[now])cout<<"1";
            else cout<<"0";
            now+=4;
        }
        cout<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
