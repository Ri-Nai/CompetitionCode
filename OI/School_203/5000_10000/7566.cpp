#include<cstdio>
#include<cstring>
const int maxn=1e6+5;
int tot,n,head[maxn],nxt[maxn],V[maxn];
double p[maxn],f[maxn],dp[maxn],W[maxn];
void Add(int u,int v,double w)
{
	V[++tot]=v;W[tot]=w;
	nxt[tot]=head[u];head[u]=tot;
}
void dfs1(int u,int fa)
{
	f[u]=1-p[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=V[i];
		if(v!=fa)dfs1(v,u),f[u]*=(1-W[i]+W[i]*f[v]);
	}
}
void dfs2(int u,int fa,int pre)
{
	if(u==1)dp[u]=f[u];
	else
	{
		double P=dp[fa]/(1-W[pre]+W[pre]*f[u]);
		dp[u]=f[u]*(1-W[pre]+W[pre]*P);
	}
	for(int i=head[u];i;i=nxt[i])
	{
		int v=V[i];
		if(v!=fa)dfs2(v,u,i);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),
		Add(u,v,w*0.01),Add(v,u,w*0.01);
	for(int i=1,t;i<=n;++i)scanf("%d",&t),p[i]=t*0.01;
	dfs1(1,0),dfs2(1,0,0);double ans=0;
	for(int i=1;i<=n;++i)ans+=1-dp[i];
	printf("%.6lf",ans);
}