#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<(X)<<'\n',void()
namespace T
{
    typedef pair<int,int> Pr;
    int n;
    const int N=1e5+5;
    int A[N],ans;
    vector<int>E[N];
    Pr P[N];
    void dfs(int u,int f)
    {
        if(A[u])return P[u]={A[u],A[u]},void();
        auto &[x,y]=P[u];
        x=1e9;y=-1e9;
        for(int v:E[u])
        {
            if(v==f)continue;
            dfs(v,u);
            auto &[a,b]=P[v];
            if(a<x)x=a;
            if(b>y)y=b;
        }
    }
    void change(Pr &p,int x)
    {
        if(P[x].first<p.first)p.first=P[x].first;
        if(P[x].second>p.second)p.second=P[x].second;
    }
    void dfsans(int u,int fa,Pr f)
    {
        int mx=f.second-f.first;
        for(int v:E[u])
            if(v!=fa)mx=max(mx,P[v].second-P[v].first);
        ans=min(ans,mx);
        for(int v:E[u])
        {
            if(v==fa)continue;
            if(!A[v])
            {
                Pr tmp=f;
                for(int p:E[u])
                    if(p!=v and p!=fa)change(tmp,p);
                dfsans(v,u,tmp);
            }
        }
    }
    void solve()
    {
        cin>>n;
        // int mn=1e9;`
        for(int i=1;i<=n;++i)
            cin>>A[i];
        // for(int i=1;i<=n;++i)A[i]-=mn;
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1,0);
        ans=2e9;
        dfsans(1,0,{1e9,-1e9});
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    T::solve();
}
