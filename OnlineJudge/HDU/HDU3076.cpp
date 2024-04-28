#include<cstdio>
double P1,P2,A[7],B[7],dp[2020][2020];
int n,m;
double dfs(int n,int m)
{
	if(!m)return 1.0;
	if(!n)return 0.0;
	if(dp[n][m]>-0.9)return dp[n][m];
	return dp[n][m]=dfs(n-1,m)*P2+dfs(n,m-1)*P1;
}
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		for(int i=1;i<=6;++i)scanf("%lf",&A[i]);
		for(int i=1;i<=6;++i)scanf("%lf",&B[i]);
		P1=P2=0.0;
		for(int i=1;i<=6;++i)
			for(int j=1;j<=6;++j)
			{
				if(i>j)P1+=A[i]*B[j];
				if(i<j)P2+=A[i]*B[j];
			}
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				dp[i][j]=-1.0;
		if(P1+P2!=0.0)
		{
			double tmp=P1+P2;
			P1/=tmp;P2/=tmp;
		}
		printf("%.6lf\n",dfs(n,m));
	}
}