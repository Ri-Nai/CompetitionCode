#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8,mod=998244353;
typedef long long ll;
int n;
int A[N];
string S[N];
struct Edge
{
    int v;
    string c;
};
vector<Edge>E[N];
namespace P20
{
    void dfs(int u,int f,string now)
    {
        for(auto T:E[u])
        {
            int v=T.v;
            if(v==f)continue;
            string c=T.c,tmp=now;
            tmp+=c;
            S[v]=tmp;
            dfs(v,u,S[v]);
        }
    }
    int get(int u,int v)
    {
        int l=min(S[u].size(),S[v].size());
        for(int i=0;i<l;++i)
            if(S[u][i]!=S[v][i])
                return i;
        return l;
    }
    void Solve()
    {
        dfs(1,1,"");
        ll ans=0;
        for(int i=2;i<=n;++i)
        {
            for(int j=2;j<i;++j)
                ans+=2*get(i,j);
        }
        cout<<ans<<'\n';
    }
} // namespace P20
namespace P60
{
    int sz[N];
    ll ans;
    void dfs(int u,int f,int d)
    {
        sz[u]=1;
        for(auto T:E[u])
        {
            int v=T.v;
            if(v==f)continue;
            dfs(v,u,d+1);
            sz[u]+=sz[v];
        }
        for(int i=0;i<E[u].size();++i)
        {
            int v1=E[u][i].v;
            if(v1==f)continue;
            string c1=E[u][i].c;
            for(int j=i+1;j<E[u].size();++j)
            {
                int v2=E[u][j].v;
                if(v2==f)continue;
                string c2=E[u][j].c;
                ans+=2ll*(d+(c1==c2)+1)*sz[v1]*sz[v2];
            }
        }
    }
    void Solve()
    {
        dfs(1,1,0);
        cout<<ans<<'\n';
    }
} // namespace P60

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        string c;
        cin>>u>>v>>c;
        E[u].push_back((Edge){v,c});
        E[v].push_back((Edge){u,c});
    }
    // if(n<=500)P20::Solve();
    // else
    P60::Solve();
}
