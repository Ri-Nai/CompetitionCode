#include<cstdio>
double p,dp[25];
int main()
{
	while(~scanf("%lf",&p))
	{
		for(int i=19;~i;--i)
			dp[i]=(dp[i+1]-dp[i+3]*(1-p)+1)/p;
		printf("%f\n",dp[0]+dp[1]);
	}
}