#include<cstdio>
const int maxn=2e5+5;
int head[maxn],to[maxn],nxt[maxn],tot,sz[maxn];
double f[maxn];
void Add(int u,int v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void pre(int now)
{
	sz[now]=1;
	for(int i=head[now];i;i=nxt[i])
		pre(to[i]),sz[now]+=sz[to[i]];
}
void dfs(int now)
{
	for(int i=head[now];i;i=nxt[i])
		f[to[i]]=f[now]+(sz[now]-sz[to[i]]+1)/2.0,dfs(to[i]);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=2,x;i<=n;++i)
		scanf("%d",&x),Add(x,i);
	pre(1);f[1]=1;dfs(1);
	for(int i=1,x;i<n;++i)
		printf("%lf ",f[i]);
		printf("%lf\n",f[n]);
}