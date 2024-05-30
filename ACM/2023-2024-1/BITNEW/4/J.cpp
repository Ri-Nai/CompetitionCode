#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=22,M=1e4+4;
    const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    int n,m,x0,y0;
    int A[N][M];
    ll dis1[N][M],dis2[N][M],ans=1e18;
    bool mark[N][M];
    struct Point
    {
        int x,y;
        ll dis;
        Point(int _,int __,ll ___){x=_,y=__,dis=___;}
        bool operator < (const Point &_)const
        {
            return dis>_.dis;
        }
    };
    void Dijkstra(int x1,int y1,int x2,int y2,int sx,int sy,ll dis[N][M])
    {
        for(int i=x1;i<=x2;++i)
            for(int j=y1;j<=y2;++j)
                dis[i][j]=1e18,mark[i][j]=0;
        priority_queue<Point>Q;
        Q.push(Point(sx,sy,dis[sx][sy]=0));
        while(!Q.empty())
        {
            Point P=Q.top();
            Q.pop();
            int x=P.x,y=P.y;
            if(mark[x][y])continue;
            mark[x][y]=1;
            for(int i=0;i<4;++i)
            {
                int u=x+dx[i],v=y+dy[i];
                if(!~A[u][v])continue;
                if(u<x1 or u>x2 or v<y1 or v>y2)continue;
                ll now=dis[x][y]+A[u][v];
                if(dis[u][v]>now)Q.push(Point(u,v,dis[u][v]=now));
            }
        }
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>A[i][j];
                if(!~A[i][j])x0=i,y0=j;
            }
        for(int x1=1;x1<x0;++x1)
            for(int x2=x0+1;x2<=n;++x2)
            {
                Dijkstra(1,1,x0,m,x1,y0,dis1);
                Dijkstra(x0,1,n,m,x2,y0,dis2);
                ll res=1e18;
                for(int y1=1;y1<y0;++y1)
                    for(int y2=y0+1;y2<=m;++y2)
                        res=min(res,dis1[x0][y1]+dis2[x0][y1]+dis1[x0][y2]+dis2[x0][y2]-A[x0][y1]-A[x0][y2]);
                ans=min(ans,res+A[x1][y0]+A[x2][y0]);
            }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
/*
5 5
1 1 1 1 1
1 9 9 9 1
1 9 -1 9 1
1 9 9 9 1
1 1 1 1 1

6 8
13 15 25 28 88 99 74 87
20 85 20 18 14 26 18 56
40 54 11 90 91 13 41 66
30 82 51 -1 38 22 86 62
27 55 13 51 42 64 77 36
12 90 43 25 11 60 60 72
*/
