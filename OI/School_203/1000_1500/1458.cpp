#include<cstdio>
const int maxn=1e5+5;
int n,m,head[maxn],nxt[maxn<<1],dep[maxn],
to[maxn<<1],W[maxn<<1],tot,dis[maxn],fa[20][maxn];
void Add(int u,int v,int w)
{
	to[++tot]=v;W[tot]=w;
	nxt[tot]=head[u];head[u]=tot;
}
void dfs(int u,int f,int w)
{
	dep[u]=dep[f]+1;dis[u]=w;fa[0][u]=f;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)dfs(to[i],u,w+W[i]);
}
void Up(int &x,int step)
{
	for(int i=0;i<=19;++i)
		if(1<<i&step)x=fa[i][x];
}
int LCA(int u,int v)
{
	int tmp;
	if(dep[u]<dep[v])tmp=u,u=v,v=tmp;
	Up(u,dep[u]-dep[v]);
	if(u==v)return v;
	for(int i=19;~i;--i)
		if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<n;++i)
		scanf("%d%d%d",&a,&b,&c),
		Add(a,b,c),Add(b,a,c);
	dfs(1,0,0);
	for(int j=1;j<=19;++j)
		for(int i=1;i<=n;++i)
			fa[j][i]=fa[j-1][fa[j-1][i]];
	for(int i=1,a,b;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",dis[a]+dis[b]-(dis[LCA(a,b)]<<1));
	}
}