#include<cstdio>
int n,m,dp[2][35];
inline int R(int t){return (t-1+n)%n+1;}
int main()
{
	scanf("%d%d",&n,&m);dp[0][1]=1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			dp[i&1][j]=dp[i&1^1][R(j-1)]+dp[i&1^1][R(j+1)];
	printf("%d\n",dp[m&1][1]);
}