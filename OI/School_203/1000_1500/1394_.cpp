#include<cstdio>
const int maxn=1e5+5;
int n,m,fa[maxn],dis[maxn];
int find(int x)
{
	if(x==fa[x])return fa[x];
	int t=find(fa[x]);
	(dis[x]+=dis[fa[x]])&=1;
	return fa[x]=t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,dis[i]=0;
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		if(fx!=fy)fa[fx]=fy,dis[fx]=(-dis[x]+dis[y]+1)&1;
		else if(dis[x]==dis[y])
		{
			puts("there are must be something wrong");
			return 0;
		}
	}
	puts("it's your own problem");
}