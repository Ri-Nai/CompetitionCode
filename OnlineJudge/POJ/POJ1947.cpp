#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=155;
int sz[maxn],nxt[maxn],dp[maxn][maxn],
fa[maxn],n,m,RT,cnt,head[maxn],to[maxn];
inline void Add(int u,int v)
{
	to[++cnt]=v;nxt[cnt]=head[u];head[u]=cnt;++sz[u];fa[v]=u;
}
void dfs(int now)
{
	dp[now][1]=sz[now];
	for(int i=head[now];~i;i=nxt[i])
	{
		int nxt=to[i];dfs(nxt);
		for(int j=m;j;--j)
			for(int k=1;k<=j;++k)
				dp[now][j]=min(dp[now][j],dp[now][j-k]+dp[nxt][k]-1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(dp,0x3f,sizeof dp);
	memset(head,-1,sizeof head);
	for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),Add(u,v);
	for(int i=1;i<=n;++i)if(!fa[i])RT=i;
	dfs(RT);int ans=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		if(i==RT)ans=min(ans,dp[i][m]);
		else ans=min(ans,dp[i][m]+1);
	}
	printf("%d\n",ans);
}