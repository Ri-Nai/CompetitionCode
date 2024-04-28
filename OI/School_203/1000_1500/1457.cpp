#include<cstdio>
const int maxn=605;
int to[maxn],nxt[maxn],head[maxn],tot;
int n,m,A[maxn],dp[maxn][maxn];
inline void Add(const int &u,const int &v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void dfs(int x,int tot)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		for(int j=0;j<tot;++j)
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)
		scanf("%d%d",&x,&A[i]),Add(x,i);
	dfs(0);
	printf("%d\n",dp[0][m]);
}