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
        int n=rd();
        vector<int>Color(n+1);
        vector<vector<int>>E(n+1);
        vector<map<int,int>>has(n+1);
        for(int i=1;i<=n;++i)
            Color[i]=rd();
        for(int i=1;i<n;++i)
        {
            int u=rd(),v=rd();
            E[u].push_back(v);
            E[v].push_back(u);
        }
        ll ans=0;
        // cout<<has[0].size()<<'\n';
        auto dfs=[&](auto self,int u,int f)->void
        {
            int son=0;
            for(int v:E[u])
            {
                if(v==f)continue;
                self(self,v,u);
                if(has[v].size()>has[son].size())son=v;
            }
            for(int v:E[u])if(v!=f and v!=son)
            {
                for(auto [x,y]:has[v])
                {
                    if(x!=Color[u])ans+=1ll*has[son][x]*y;
                    has[son][x]+=y;
                }
            }
            if(son)
            {
                ans+=has[son][Color[u]];
                //has[u]为一个map<int,int>变量

                //1. has[u]=has[son];
                //2. swap(has[u],has[son])
                //使用1.会超时,而2.不会,如何使用一种
                //简单的赋值语句实现2的速度呢
            }
            has[u][Color[u]]=1;
        };
        dfs(dfs,1,0);
        cout<<ans<<'\n';
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
