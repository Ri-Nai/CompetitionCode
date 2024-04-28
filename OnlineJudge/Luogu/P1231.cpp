#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int a,b,c;
    const int M=2e5+5;
    int tot=1,nxt[M],head[M],Now[M];
    pair<int,int>Edge[M];
    int S,T;
    vector<int>bfn;
    void Add(int u,int v,int w)
    {
        nxt[++tot]=head[u];
        Edge[head[u]=tot]={v,w};
    }
    void Addnet(int u,int v,int w)
    {
        Add(u,v,w);Add(v,u,0);
    }
    bool BFS()
    {
        bfn.assign(T+1,0);
        bfn[S]=1;
        queue<int>Q;
        Q.push(S);
        bool flag=0;
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int i=head[u];i;i=nxt[i])
            {
                auto [v,w]=Edge[i];
                if(w==0)continue;
                if(bfn[v])continue;
                bfn[v]=bfn[u]+1;
                Q.push(v);
                if(v==T)flag=1;
            }
        }
        return flag;
    }
    int dfs(int u,int f)
    {
        if(u==T)return f;
        for(int i=Now[u];i;i=nxt[i])
        {
            Now[u]=i;
            auto &[v,w]=Edge[i];
            if(w==0)continue;
            if(bfn[v]!=bfn[u]+1)continue;
            int now=dfs(v,min(f,w));
            if(now==0)bfn[v]=-1;
            else return w-=now,Edge[i^1].second+=now,now;
        }
        return 0;
    }
    int max_flow()
    {
        int res=0;
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
        cin>>b>>a>>c;
        S=0;T=a+b+b+c+1;
        for(int i=1;i<=a;++i)Addnet(S,i,1);
        for(int i=1;i<=b;++i)Addnet(a+i,a+b+i,1);
        for(int i=1;i<=c;++i)Addnet(a+b+b+i,T,1);
        int m;
        cin>>m;
        for(int u,v;m--;)
        {
            cin>>u>>v;
            Addnet(v,u+a,1);
        }
        cin>>m;
        for(int u,v;m--;)
        {
            cin>>u>>v;
            Addnet(u+a+b,a+b+b+v,1);
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
