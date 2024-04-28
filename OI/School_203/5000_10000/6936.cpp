#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define pr std::pair<int,int>
#define mp std::make_pair
int n,m,A[105][105],B[105][105],ans,
dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool vis[105][105];
struct $
{
    int x,y,h;
    bool operator <($ _)const{return h>_.h;}
};
std::priority_queue<$>Q;
inline bool pd(const int &x,const int &y)
{
    return x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&A[i][j]),
            B[i][j]=A[i][j];
            if(i==1||i==n||j==1||j==m)
                vis[i][j]=1,Q.push(($){i,j,A[i][j]});

        }
    while(!Q.empty())
    {
        int x=Q.top().x,
            y=Q.top().y,
            h=Q.top().h;
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(!pd(xx,yy))continue;vis[xx][yy]=1;
            B[xx][yy]=std::max(B[xx][yy],h);
            Q.push(($){xx,yy,B[xx][yy]});
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans+=B[i][j]-A[i][j];
    printf("%d\n",ans);
}