#include<cstdio>
#include<cstring>
int n,H[505],C[505];
long long dp[50005],sum,ans=0;
inline long long max(const long long &a,const long long &b){return a>b?a:b;}
void solve()
{
	scanf("%d",&n);sum=0;ans=0;memset(dp,0,sizeof dp);
	for(int i=1;i<=n;++i)scanf("%d%d",&H[i],&C[i]),sum+=C[i];
	for(int i=1;i<=n;++i)
		for(int j=sum;j>=C[i];--j)
			dp[j]=max(dp[j],dp[j-C[i]]+H[i]);
	for(int i=0;i<=sum;++i)
		ans=max(ans,dp[i]*dp[i]-dp[i]*i-i*i);
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}