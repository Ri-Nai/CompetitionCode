#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    const int N=7e4+4;
    int n,q;
    vector<tuple<int,int,int> >E[N];
    int dis(int S,int spd)
    {
        queue<pair<int,int> >Q;
        vector<bool>vis(n+1);
        vis[S]=1;
        Q.push({S,0});
        int ans=0;
        while(!Q.empty())
        {
            auto [u,step]=Q.front();
            Q.pop();
            ans=step;
            for(auto [v,l,r]:E[u])
                if(!vis[v] and spd<=r and spd>=l)
                {
                    vis[v]=1;
                    Q.push({v,step+1});
                }
        }
        return ans;
    }
    void Solve()
    {
        n=rd(),q=rd();
        for(int i=1;i<n;++i)
        {
            int u=rd(),v=rd(),l=rd(),r=rd();
            E[u].emplace_back(v,l,r);
            E[v].emplace_back(u,l,r);
        }
        for(int i=1;i<=q;++i)
        {
            int spd=rd(),ans=0;
            for(int j=1;j<=n;++j)
                ans=max(ans,dis(j,spd));
            cout<<ans<<'\n';
        }
    }
}
int main()
{
    T::Solve();
}
