#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),k=rd();
        vector<vector<int>>E(n+1);
        vector<int>fa(n+1),in(n+1),sz(n+1);
        for(int i=1;i<n;++i)
        {
            int u=rd(),v=rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        auto dfs=[&](auto self,int u,int f)->void
        {
            fa[u]=f;
            for(int v:E[u])
            {
                // cout<<u<<' '<<v<<"\n";
                if(v==f)continue;
                self(self,v,u);
                ++in[u];
            }
        };
        dfs(dfs,1,0);
        auto check=[&](int t)
        {
            queue<int>Q;
            vector<int>deg=in;
            for(int i=1;i<=n;++i)
            {
                sz[i]=1;
                if(!deg[i])Q.push(i);
            }
            int cnt=0;
            while(!Q.empty())
            {
                int u=Q.front();
                // cout<<t<<' '<<u<<'\n';
                Q.pop();
                if(sz[u]>=t)++cnt;
                else sz[fa[u]]+=sz[u];
                if(!--deg[fa[u]])Q.push(fa[u]);
            }
            return cnt>k;
        };
        int l=1,r=n/(k+1),res=1;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid))
                res=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<res<<"\n";
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();
}
