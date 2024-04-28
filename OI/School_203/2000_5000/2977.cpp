#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#define ps push_back
#define pr std::pair<int,int>
#define mp std::make_pair
const int maxn=1e5+5,inf=0x3f3f3f3f;
struct $
{
	int u,v,w;
	bool operator <($ _)const{return w<_.w;}
};
int n,m,fa[maxn],root[maxn],dis[maxn],ans[maxn];
bool vis[maxn];
std::vector<$>E[maxn],RD,NT;
int find(int x){return x==root[x]?x:root[x]=find(root[x]);}
void init()
{
	for(int i=0;i<RD.size();++i)
	{
		int u=RD[i].u,w=RD[i].w,v=RD[i].v;
		if(dis[v]!=dis[u]+w&&dis[u]!=dis[v]+w)
			NT.ps(($){u,v,dis[u]+dis[v]+w});
		//printf("%d\n",i);
	}
	std::sort(NT.begin(),NT.end());
	for(int i=1;i<=n;++i)root[i]=i;
	memset(ans,inf,sizeof ans);
}
void Dijkstra()
{
	std::priority_queue<pr,std::vector<pr>,std::greater<pr> >Q;
	memset(dis,inf,sizeof dis);
	dis[1]=0;Q.push(mp(0,1));
	while(!Q.empty())
	{
		int now=Q.top().second;Q.pop();
		if(!vis[now])
		{
			vis[now]=1;
			for(int i=0;i<E[now].size();++i)
			{
				int to=E[now][i].v,val=E[now][i].w;
				if(dis[now]+val<dis[to])
					dis[to]=dis[now]+val,
					fa[to]=now,Q.push(mp(dis[to],to));
			}
		}
	}
}
void in_put()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&u,&v,&w),
		E[u].ps(($){u,v,w}),
		E[v].ps(($){v,u,w}),
		RD.ps(($){u,v,w});
}
void solve()
{
	for(int i=0;i<NT.size();++i)
	{
		int l=find(NT[i].u),r=find(NT[i].v),val=NT[i].w;
		while(l!=r)
		{
			if(dis[l]<dis[r])std::swap(l,r);
			//printf("%d %d\n",l,r);
			//printf("%d %d\n",val,dis[l]);
			ans[l]=val-dis[l];
			root[l]=fa[l];
			l=find(l);
		}
	}
	for(int i=2;i<=n;++i)printf("%d\n",ans[i]==inf?-1:ans[i]);
}
int main()
{
	in_put();
	Dijkstra();
	init();
	solve();
}