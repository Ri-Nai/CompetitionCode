#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,t;
struct Edge
{
    int v,l,w;
};
struct Point
{
    int u;
    double w;
    bool operator <(const Point &_)const
    {
        return w>_.w;
    }
};
vector<Edge>E[N];
double dis[N];
bool mark[N];
double Dijkstra(double ex)
{
    priority_queue<Point>Q;
    for(int i=1;i<=n;++i)dis[i]=1e12,mark[i]=0;
    dis[1]=0;
    Q.push((Point){1,0});
    while(!Q.empty())
    {
        int u=Q.top().u;
        Q.pop();
        if(mark[u])continue;
        if(u==n)return dis[u];
        mark[u]=1;
        for(auto t:E[u])
        {
            int v=t.v;
            int l=t.l;
            double w=ex+t.w;
            double now=l/w;
            if(dis[v]>dis[u]+now)
            {
                dis[v]=dis[u]+now;
                Q.push((Point){v,dis[v]});
            }
        }
    }
    return dis[n];
}
void Solve()
{
    cin>>n>>m>>t;
    long long sum=0;
    for(int i=1;i<=m;++i)
    {
        int u,v,l,w;
        scanf("%d%d%d%d",&u,&v,&l,&w);
        E[u].push_back((Edge){v,l,w});
        E[v].push_back((Edge){u,l,w});
        sum+=l;
    }
    if(Dijkstra(0)<=t)
    {
        cout<<"0\n";
        return ;
    }
    double L=0,R=sum/t;
    while(R-L>8e-7)
    {
        double mid=(L+R)/2;
        if(Dijkstra(mid)<=t)R=mid;
        else L=mid;
    }
    printf("%.6lf\n",L);
}
int main()
{
    // ios::sync_with_stdio(0);
    Solve();
}
