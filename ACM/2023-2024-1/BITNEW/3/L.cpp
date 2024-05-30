#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=505;
    vector<int>E[M];
    int n,A[M],fa[M],dep[M];
    void dfs(int u,int d)
    {
        dep[u]=d;
        for(int i=0;i<E[u].size();++i)
            dfs(E[u][i],d+1);
    }
    int lca(int u,int v,int p)
    {
        if(A[u]!=A[v])return 0;
        if(dep[u]<dep[v])swap(u,v);
        while(dep[u]>dep[v])
        {
            if(A[u]!=p)return 0;
            u=fa[u];
        }
        if(u==v)return 1;
        return 0;
    }
    void solve()
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)
        {
            int t=2;
            while(t--)
            {
                int x;cin>>x;
                if(x)fa[x]=i,E[i].push_back(x);
            }
        }
        dfs(1,0);
        for(int u=1;u<=n;++u)
            for(int v=u+1;v<=n;++v)
                ans+=lca(u,v,A[v]);
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
