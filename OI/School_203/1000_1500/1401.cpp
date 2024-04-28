#include<cstdio>
#include<algorithm>
const int maxn=1e5+5;
int n,m,fa[maxn],dis[maxn];
struct $
{
	int u,v,w;
	void read(){scanf("%d%d%d",&u,&v,&w);}
	bool operator <(const $&_){return w>_.w;}
}A[maxn];
int find(int x)
{
	if(x==fa[x])return fa[x];
	int t=find(fa[x]);
	(dis[x]+=dis[fa[x]])&=1;
	return fa[x]=t;
}
int solve()
{
	for(int i=1;i<=m;++i)
	{
		int x=A[i].u,y=A[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy)fa[fx]=fy,dis[fx]=(-dis[x]+dis[y]+1)&1;
		else if(dis[x]==dis[y])
			return A[i].w;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,dis[i]=0;
	for(int i=1,u,v,w;i<=m;++i)
		A[i].read();
	std::sort(A+1,A+m+1);
	printf("%d\n",solve());
}