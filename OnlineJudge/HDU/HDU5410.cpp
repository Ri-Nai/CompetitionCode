#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m,dp[2005],p,a,b;
void solve()
{
	memset(dp,0,sizeof dp);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&p,&a,&b);
		for(int j=m;j>=p;--j)
			dp[j]=std::max(dp[j],dp[j-p]+a+b);
		for(int j=p;j<=m;++j)
			dp[j]=std::max(dp[j],dp[j-p]+a);
	}
	printf("%d\n",dp[m]);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();

}
