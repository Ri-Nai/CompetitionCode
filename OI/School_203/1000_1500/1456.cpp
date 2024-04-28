#include<cstdio>
#include<vector>
#include<algorithm>
const int maxn=2e5+5;
int ans,dp[2][maxn],val[maxn],n,fa[maxn],root;
std::vector<int>E[maxn];
void in_put()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		E[u].push_back(v),fa[v]=u;
	for(int i=1;i<=n;++i)if(!fa[i])root=i;
}
void dfs(int now)
{
	dp[1][now]=val[now];
	for(int i=0;i<E[now].size();++i)
	{
		int nxt=E[now][i];dfs(nxt);
		dp[1][now]+=std::max(0,dp[0][nxt]);
		dp[0][now]+=std::max(0,std::max(dp[0][nxt],dp[1][nxt]));
	}
}
int main()
{
	in_put();
	dfs(root);
	printf("%d\n",std::max(dp[0][root],dp[1][root]));
}