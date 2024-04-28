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
        int n=rd(),m=rd();
        map<int,int>id;
        vector<vector<pair<int,int>>>E(n+1);
        int cnt=n;
        for(int i=1;i<=m;++i)
        {
            int u=rd(),v=rd(),w=rd();
            E[u].emplace_back(v,w);
            E[v].emplace_back(u,w);
            if(!id[w])id[w]=++cnt;
        }
        int bg=rd(),ed=rd();
        vector<set<int>>P(cnt+1);
        for(int u=1;u<=n;++u)
            for(auto [v,w]:E[u])
            {
                int t=id[w];
                P[u].insert(t);
                P[t].insert(u);
                P[v].insert(t);
                P[t].insert(v);
            }
        queue<int>Q;
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
