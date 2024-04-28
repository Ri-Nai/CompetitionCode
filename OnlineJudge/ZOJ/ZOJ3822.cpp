#include<cstdio>
#include<cstring>
int n,m;
double dp[2505][55][55];
void solve()
{
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	int sum=n*m;dp[1][1][1]=1;
	double ans=0;
	for(int i=1;i<=n*m;++i)
	{
		int rest=sum-i+1;//上一次剩下的
		for(int j=1;j<=n;++j)
			for(int k=1;k<=m;++k)
			{
				if(j!=n||k!=m)
					dp[i][j][k]+=dp[i-1][j][k]*(j*k-i+1)/rest;
				dp[i][j][k]+=dp[i-1][j-1][k]*((n-j+1)*k)/rest;
				dp[i][j][k]+=dp[i-1][j][k-1]*((m-k+1)*j)/rest;
				dp[i][j][k]+=dp[i-1][j-1][k-1]*(n-j+1)*(m-k+1)/rest;
			}
		ans+=i*dp[i][n][m];

	}
	printf("%.12lf\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}