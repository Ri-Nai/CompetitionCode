#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[1<<16],cnt[16][1<<16],ans[1<<16];
bool mark[20][20];
int solve(int p)
{
	if(ans[p])return ans[p];
	if(dp[p]<=k)return ans[p]=1;
	int res=16;
	for(int i=p;i;i=(i-1)&p)
		if(i!=p)res=min(res,solve(i)+solve(p^i));
	return ans[p]=res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);--u,--v;
		mark[u][v]=mark[v][u]=1;
	}
	for(int i=0;i<n;++i)
		for(int j=1;j<(1<<n);++j)if(!(1<<i&j))
			for(int k=0;k<n;++k)if(1<<k&j)
				cnt[i][j]+=mark[i][k];
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<(1<<n)-1;++i)
		for(int j=0;j<n;++j)if(!(1<<j&i))
			dp[i|1<<j]=min(dp[i|1<<j],dp[i]+cnt[j][i]);
	printf("%d\n",solve((1<<n)-1));

}