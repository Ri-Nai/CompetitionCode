#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=2e5+5;
    int n,m;
    vector<int>V[N];
    vector<ll> W[N];
    ll dis[N][2],T[N];
    bool mark[N][2];
    void Add(int u,int v,ll w)
    {
        V[u].push_back(v);
        W[u].push_back(w);
    }
    struct Pr
    {
        int pt,tm;
        ll D;
        Pr(int _,int __,ll ___){pt=_,tm=__,D=___;}
        bool operator < (const Pr &_)const
        {
            if(tm==_.tm)return D>_.D;
            return tm>_.tm;
        }
    };
    void solve()
    {
        cin>>n>>m;
        for(int i=2;i<=n-1;++i)
            cin>>T[i];
        for(int i=1;i<=m;++i)
        {
            int u,v;
            ll w;
            cin>>u>>v>>w;
            Add(u,v,w);
            Add(v,u,w);
        }
        memset(dis,0x3f,sizeof dis);
        dis[1][0]=0;
        priority_queue<Pr>Q;
        Q.push(Pr(1,0,0));
        while(!Q.empty())
        {
            int u=Q.top().pt,t=Q.top().tm;
            mark[u][t]=1;
            Q.pop();
            for(int i=0;i<int(V[u].size());++i)
            {
                int v=V[u][i];
                ll w=W[u][i];
                ll &td=dis[v][t];
                ll now=w+T[v];
                if(dis[u][t]+now<td)
                {
                    td=dis[u][t]+now;
                    Q.push(Pr(v,t,td));
                }
                if(t==0)
                {
                    ll &ttd=dis[v][1];
                    if(dis[u][0]+w<ttd)
                    {
                        ttd=dis[u][0]+w;
                        Q.push(Pr(v,1,ttd));
                    }
                }
            }
        }
        cout<<min(dis[n][0],dis[n][1])<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    T::solve();

}
