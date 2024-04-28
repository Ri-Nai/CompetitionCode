#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define pr std::pair<int,int>
#define mp std::make_pair
const int maxn=2e4+5;
int n,m,dis[maxn],ans;
bool vis[maxn];
std::vector<pr>E1[maxn],E2[maxn];
void Dijkstra();
void bfs();
void in_put()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v,w;i<=m;++i)
        scanf("%d%d%d",&u,&v,&w),
        E1[u].push_back(mp(v,w)),
        E2[v].push_back(mp(u,w));
}
int main()
{
    in_put();Dijkstra();bfs();
    printf("%d %d\n",dis[n],ans);
}
void bfs()
{
    std::queue<int> Q;
    memset(vis,0,sizeof(vis));
    Q.push(n);vis[n]=1;
    while(!Q.empty())
    {
        int now=Q.front();Q.pop();
        for(int i=0;i<E2[now].size();++i)
        {
            int to=E2[now][i].first,val=E2[now][i].second;
            if(dis[now]==dis[to]+val)
            {
                ++ans;
                if(!vis[to])vis[to]=1,Q.push(to);
            }
        }
    }
}
void Dijkstra()
{
    std::priority_queue<pr,std::vector<pr>,std::greater<pr> >Q;
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;Q.push(mp(0,1));
    while(!Q.empty())
    {
        int now=Q.top().second;Q.pop();
        if(!vis[now])
        {
            vis[now]=1;
            for(int i=0;i<E1[now].size();++i)
            {
                int to=E1[now][i].first,val=E1[now][i].second;
                if(dis[now]+val<dis[to])
                    dis[to]=dis[now]+val,
                    Q.push(mp(dis[to],to));
            }
        }
    }    
}
