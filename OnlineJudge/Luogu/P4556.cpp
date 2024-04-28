#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=1e5+5,M=3e7+4;
    vector<int>E[N];
    int fa[N][20],dep[N];
    int id,cnt[M],pos[M],ls[M],rs[M],rt[N];
    int ans[N];
    int LCA(int u,int v)
    {
        if(dep[u]<dep[v])swap(u,v);
        for(int d=dep[u]-dep[v],i=0;d;d>>=1,++i)
            if(d&1)u=fa[u][i];
        if(u==v)return u;
        for(int i=19;i>=0;--i)
            if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];
        return fa[u][0];
    }
    void pushup(int p)
    {
        if(cnt[ls[p]]>=cnt[rs[p]])pos[p]=pos[ls[p]];
        else pos[p]=pos[rs[p]];
        cnt[p]=max(cnt[ls[p]],cnt[rs[p]]);
    }
    void Upd(int x,int y,int &p,int L=1,int R=100000)
    {
        if(!p)p=++id;
        if(L==R)
        {
            cnt[p]+=y;
            pos[p]=x;
            return ;
        }
        int mid=L+R>>1;
        if(x<=mid)Upd(x,y,ls[p],L,mid);
        else Upd(x,y,rs[p],mid+1,R);
        pushup(p);
        // cout<<p<<' '<<ls[p]<<' '<<rs[p]<<'\n'
        //     <<cnt[p]<<' '<<cnt[ls[p]]<<' '<<cnt[rs[p]]<<'\n'
        //     <<pos[p]<<' '<<pos[ls[p]]<<' '<<pos[rs[p]]<<'\n'
        //     <<'\n';
    }
    void Merge(int &p,int q,int L=1,int R=100000)
    {
        if(!q)return;
        if(!p){p=q;return;}
        if(L==R)
        {
            cnt[p]+=cnt[q];
            pos[p]=L;
            return ;
        }
        int mid=L+R>>1;
        Merge(ls[p],ls[q],L,mid);
        Merge(rs[p],rs[q],mid+1,R);
        pushup(p);
        // cout<<"*"<<p<<' '<<ls[p]<<' '<<rs[p]<<'\n'
        //     <<cnt[p]<<' '<<cnt[ls[p]]<<' '<<cnt[rs[p]]<<'\n'
        //     <<pos[p]<<' '<<pos[ls[p]]<<' '<<pos[rs[p]]<<'\n'
        //     <<'\n';
    }
    void dfs(int u,int f)
    {
        for(int v:E[u])
        {
            if(v==f)continue;
            dfs(v,u);
            Merge(rt[u],rt[v]);
        }
        ans[u]=cnt[rt[u]]?pos[rt[u]]:0;
    }
    void init(int u,int f)
    {
        fa[u][0]=f;
        dep[u]=dep[f]+1;
        for(int i=1;i<20;++i)
            fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int v:E[u])
        {
            if(v==f)continue;
            init(v,u);
        }
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1,u,v;i<n;++i)
        {
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        init(1,0);
        for(int i=1,u,v,w;i<=m;++i)
        {
            cin>>u>>v>>w;
            int l=LCA(u,v),f=fa[l][0];
            Upd(w,1,rt[u]);
            Upd(w,1,rt[v]);
            Upd(w,-1,rt[l]);
            if(f)Upd(w,-1,rt[f]);
        }
        dfs(1,0);
        for(int i=1;i<=n;++i)
            // cout<<rt[i]<<' '<<cnt[rt[i]]<<' '<<pos[rt[i]]<<'\n';
            cout<<ans[i]<<'\n';
        return;
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();
    return 0;

}
