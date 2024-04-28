#include<cstdio>
const int maxn=2e5+5;
int n,m,head[maxn],nxt[maxn],
to[maxn],val[maxn],size[maxn],tot;
bool mark[maxn];
double dp[maxn];
void Add(int u,int v,int w)
{
	to[++tot]=v;val[tot]=w;++size[u];
	nxt[tot]=head[u];head[u]=tot;
}
double dfs(int id)
{
	if(id==n)return 0.0;
	if(mark[id])return dp[id];
	mark[id]=1;
	for(int i=head[id];i;i=nxt[i])
		dp[id]+=(dfs(to[i])+val[i])/size[id];
	return dp[id];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&u,&v,&w),Add(u,v,w);
	printf("%.2lf\n",dfs(1));
}