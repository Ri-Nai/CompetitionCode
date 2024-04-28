#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
const int maxn=2005;
LL n,A[maxn],B[maxn],dp[maxn],sum[maxn];
void solve()
{
	scanf("%lld",&n);int ans=0;
	memset(dp,0x3f,sizeof dp);
	LL inf=dp[0];dp[0]=0;
	for(int i=1;i<=n;++i)scanf("%lld",&A[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&B[i]),sum[i]=sum[i-1]+B[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j;--j)
			if(dp[j-1]+A[i]<=sum[i])
				dp[j]=std::min(dp[j],dp[j-1]+A[i]);
	}
	for(int i=n;~i;--i)
		if(dp[i]<inf)
		{
			printf("%d\n",i);
			return ;
		}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}
/*
1
5
5 3 5 3 5
1 2 3 4 5
*/