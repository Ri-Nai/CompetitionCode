#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,m;
    int fa[N];
    bool mark[N];
    vector<int>E[N];
    int now,ans;
    void dfs(int u)
    {
        if(mark[u])return;
        mark[u]=1;
        for(int v:E[u])
        {
            while(now<v)
            {
                ++ans;
                // cout<<u<<' '<<v<<'\n';
                dfs(now++);
            }
            if(now==v)dfs(now++);
        }
        if(u==1)while(now<=n)++ans,dfs(now++);
    }
    void solve()
    {
        cin>>n>>m;
        now=2;
        for(int i=1;i<=n;++i)
            mark[i]=0,fa[i]=i,E[i].clear();
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            if(y<x)swap(x,y);
            if(y==x)continue;
            // fa[find(y)]=find(x);
            // mark[y]=1;
            E[x].push_back(y);
        }
        for(int i=1;i<=n;++i)
            sort(E[i].begin(),E[i].end());
        ans=0;
        dfs(1);
        cout<<ans<<'\n';
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
/*
   1
  2 3
   4


1:2
1:3
2:4
4:5
3:6
*/
