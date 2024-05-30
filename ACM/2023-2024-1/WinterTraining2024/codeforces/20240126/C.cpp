#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,m;
    int fa[N];
    bool can[N];
    typedef pair<int,int> Pr;
    vector<Pr>E;
    map<Pr,int>mp;
    int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)fa[i]=i;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            mp[{x,y}]=1;
            E.push_back({x,y});
        }
        for(auto &[x,y]:E)
            if(!mp[{y,x}])can[y]=1;
        for(auto &[x,y]:E)if(mp[{y,x}])
        {
            mp[{x,y}]=0;
            int u=find(x),v=find(y);
            if(u!=v)fa[v]=u,can[u]|=can[v];
            else can[u]=1;
        }
        for(int i=1;i<=n;++i)if(!can[find(i)])End("NO");
        End("YES");
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
