#include<cstdio>
double dp[1<<21],p[20];
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		dp[(1<<n)-1]=0;
		for(int i=0;i<n;++i)
			scanf("%lf",&p[i]);
		for(int i=(1<<n)-2;~i;--i)
		{
			double sum=0,num=0;
			for(int j=0;j<n;++j)
				if(!(i&1<<j))
					sum+=p[j]*dp[i|1<<j],num+=p[j];
			dp[i]=(sum+1)/num;
		}
		printf("%.10lf\n",dp[0]);
	}
}