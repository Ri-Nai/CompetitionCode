#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define End(X) return cout<<X<<'\n',void()
map<ull,int>mp;
const int P=1e9+7;
namespace T
{
    const int M=2e4+5;
    char s[M];
    ull hsh[M];
    int n,m,id,ans;
    bool mk1[M],mk2[M];
    int nxt[M],to[M],head[M],tot;
    int fa[M],son[M],in[M],can[M],ri[M];
    int calc(int l,int r,int &f)
    {
        ull str=hsh[r]-hsh[l];
        if(!mp[str])mp[str]=++id;
        int u=mp[str];
        if(~f and fa[u]!=f)++in[f],son[f]=u;
        fa[u]=f;
        f=u;return u;
    }
    void input(int p)
    {
        cin>>s+1;
        int len=strlen(s+1);
        int lst=0,f=-1;
        for(int j=1;j<=len;++j)
        {
            hsh[j]=hsh[j-1]*P+s[j];
            if(s[j]=='/')
                calc(j,lst,f),lst=j;
        }
        can[calc(len,lst,f)]=p;
    }
    void Add(int u,int v)
    {
        if(!~u)return;
        nxt[++tot]=head[u];
        ++ri[to[head[u]=tot]=v];
    }
    void dfs1(int u)
    {
        if(can[u]==1)mk1[u]=1;
        if(can[u]==-1)mk2[u]=1;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            dfs1(v);
            mk1[u]|=mk1[v];
            mk2[u]|=mk2[v];
        }
    }
    void dfs2(int u)
    {
        if(mk1[u] and !mk2[u])return ++ans,void();
        for(int i=head[u];i;i=nxt[i])
            dfs2(to[i]);
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)input(1);
        for(int i=1;i<=m;++i)input(-1);
        for(int i=1;i<=n;++i)
        for(int i=1;i<=id;++i)
            if(in[i]==1 and !can[i])fa[son[i]]=fa[i],in[i]=-1;
        // for(int i=1;i<=id;++i)
        //     cout<<i<<' '<<fa[i]<<' '<<in[i]<<' '<<can[i]<<'\n';
        for(int i=1;i<=id;++i)
            if(~in[i] and ~fa[i])
            // cout<<fa[i]<<' ' <<i<<'\n',
            Add(fa[i],i);

        for(int i=1;i<=id;++i)if(!ri[i] and ~in[i])dfs1(i);
        // for(int i=1;i<=id;++i)if(!ri[i] and ~in[i])cout<<i<<' '<<mk1[i]<<' '<<mk2[i]<<' '<<can[i]<<'\n';
        for(int i=1;i<=id;++i)if(!ri[i] and ~in[i])dfs2(i);
        cout<<ans<<'\n';
        for(int i=1;i<=id;++i)fa[i]=-1,mk1[i]=mk2[i]=can[i]=ri[i]=in[i]=0;
        for(int i=1;i<=id;++i)head[i]=0;
        ans=tot=id=0;mp.clear();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
