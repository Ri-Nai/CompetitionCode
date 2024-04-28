#include<cstdio>
int n,h;long long dp[40][40];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=0;i<=n;++i)dp[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<=j;++k)
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1];
	printf("%lld\n",dp[n][n]-dp[h-1][n]);
}