#include<cstdio>
#include<algorithm>
double dp[10005];
int n,m;
int main()
{
	while(1)
	{
		scanf("%d%d",&m,&n);if(!n&&!m)break;
		double ans=1;
		for(int i=0;i<=m;++i)dp[i]=1;
		for(int i=1;i<=n;++i)
		{
			int C;double A;
			scanf("%d%lf",&C,&A);
			for(int j=m;j>=C;--j)
				ans=std::min(dp[j]=std::min(dp[j],dp[j-C]*(1.0-A)),ans);
		}
		printf("%.1lf%%\n",(1.0-ans)*100);
	}
}