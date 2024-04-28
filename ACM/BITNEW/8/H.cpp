#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,A[N];
    ll dis[N],ans;
    struct Pr
    {
        int v,w;
    };
    vector<Pr>E[N];
    void dfs(int u)
    {
        for(Pr t:E[u])
        {
            int v=t.v,w=t.w;
            dis[v]=dis[u]+w;
            ans=max(ans,dis[v]+A[v]);
            dfs(v);
        }
    }
    void solve()
    {
        cin>>n;
        for(int i=2;i<=n;++i)
            cin>>A[i];
        for(int i=2;i<=n;++i)
        {
            int x,y,z;
            cin>>x>>y>>z;
            E[x].push_back((Pr){y,z});
        }
        dfs(1);
        cout<<ans<<'\n';
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
