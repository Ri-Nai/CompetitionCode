#include<cstdio>
double dp[100005];
void solve()
{
	int n;double p;
	scanf("%d%lf",&n,&p);
	dp[n]=0;
	for(int i=n-1;i;--i)
	{
		double sum=1.0*(n-1)*n/2,num=1.0*i*(n-i);
		double p0=p*num/sum;
		dp[i]=(dp[i+1]*p0+1)/p0;
	}
	printf("%.3lf\n",dp[1]);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}