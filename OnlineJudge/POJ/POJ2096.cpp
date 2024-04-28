#include<cstdio>
double dp[1005][1005];
void solve()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		dp[n][m]=0;
		for(int i=n;~i;--i)
		{
			for(int j=m;~j;--j)
			{
				if(i==n&&j==m)continue;
				dp[i][j]=n*m;
				dp[i][j]+=(n-i)*j*dp[i+1][j];
				dp[i][j]+=i*(m-j)*dp[i][j+1];
				dp[i][j]+=(n-i)*(m-j)*dp[i+1][j+1];
				dp[i][j]/=(n*m-i*j);

			}
		}
		printf("%.4lf\n",dp[0][0]);
	}
}
int main()
{
	solve();
}