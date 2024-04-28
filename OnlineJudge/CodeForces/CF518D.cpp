#include<cstdio>
#include<cstring>
int n,t;
double dp[2][2005],p;
int main()
{
	while(~scanf("%d%lf%d",&n,&p,&t))
	{
		memset(dp,0,sizeof dp);
		int cur=0;dp[0][0]=1;
		for(int i=1;i<=t;++i)
		{
			cur^=1;
			for(int j=0;j<n;++j)
			{
				if(j==0)dp[cur][j]=dp[cur^1][j]*(1-p);
				else dp[cur][j]=dp[cur^1][j]*(1-p)+dp[cur^1][j-1]*p;
			}
			dp[cur][n]=dp[cur^1][n]+dp[cur^1][n-1]*p;
		}
		double ans=0;
		for(int i=1;i<=n;++i)ans+=dp[cur][i]*i;
		printf("%lf\n",ans);
	}
}