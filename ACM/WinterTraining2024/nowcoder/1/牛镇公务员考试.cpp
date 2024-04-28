#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    const int N=1e5+5;
    const int mod=998244353;
    int n;
    int to[N],in[N];
    int vis[N];
    int chr[N];
    string s[N];
    int ans=1;
    int dfs(int u,int p)
    {
        if(vis[u])return chr[u]==p;
        vis[u]=1;
        in[u]=0;
        int res=dfs(to[u],s[u][p]-'A');
        vis[u]=0;
        return res;
    }
    void work(int u)
    {
        int now=0;
        for(int i=0;i<5;++i)
        {
            chr[u]=i;
            now+=dfs(u,i);
            // cout<<now<<'\n';
        }
        ans=1ll*ans*now%mod;
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int v;cin>>v>>s[i];
            ++in[to[i]=v];
        }
        queue<int>Q;
        for(int i=1;i<=n;++i)
            if(!in[i])Q.push(i);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            vis[u]=1;
            // cout<<u<<'\n';
            if(!--in[to[u]])Q.push(to[u]);
        }
        for(int i=1;i<=n;++i)
            if(in[i])work(i);
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
