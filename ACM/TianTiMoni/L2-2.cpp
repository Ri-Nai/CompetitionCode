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
    typedef long long ll;
    typedef pair<int,int> Pr;
    const int N=2e5+5;
    vector<Pr>E[N];
    vector<int>has[N];
    int C[N];
    bool mark[N],vis[N];
    struct Point
    {
        ll dis,id;
        bool operator <(const Point &_)const
        {
            return dis>_.dis;
        }
    };
    ll dis[N];
    void Solve()
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            has[C[i]=rd()].push_back(i);
        for(int i=1;i<=m;++i)
        {
            int u=rd(),v=rd(),w=rd();
            E[u].emplace_back(v,w);
            E[v].emplace_back(u,w);
        }
        priority_queue<Point>Q;
        memset(dis,0x3f,sizeof dis);
        dis[1]=0;
        Q.push({0,1});
        while(!Q.empty())
        {
            auto [now,u]=Q.top();
            Q.pop();
            if(vis[u])continue;
            vis[u]=1;
            if(!mark[C[u]])
            {
                mark[C[u]]=1;
                for(int x:has[C[u]])
                {
                    dis[x]=now;
                    Q.push({dis[x],x});
                }
            }
            for(auto [v,w]:E[u])
            {
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    Q.push({dis[v],v});
                }
            }
        }
        if(!vis[n])cout<<"-1\n";
        else cout<<dis[n]<<'\n';

    }
}
int main()
{
    T::Solve();
}
