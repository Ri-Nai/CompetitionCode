#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
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
        int n=rd();
        vector<vector<Pr>>E(4);
        for(int i=1;i<=n;++i)
        {
            int u=rd(),v=rd(),w=rd();
            if(w)E[v].push_back({u,-1});
            else E[u].push_back({v,0});
        }
        queue<int>Q;
        vector<int>vis(4,1);
        vector<int>dis(4),in(4);
        for(int i=1;i<=3;++i)Q.push(i);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            vis[u]=0;
            for(auto [v,w]:E[u])
            {
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    if(!vis[v])vis[v]=1,Q.push(v),++in[v];
                    if(in[v]==6)End("No");
                }
            }
        }
        End("Yes");
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
