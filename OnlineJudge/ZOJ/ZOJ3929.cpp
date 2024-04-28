#include<cstdio>
#include<cstring>
#define LL long long
const int mod=1e9+7,maxn=1e5+5;
LL f[maxn],sum[maxn],num[maxn],dp[maxn];
void init()
{
	f[1]=f[2]=1;
	for(int i=1;i<maxn;++i)
	{
		if(i>2)f[i]=(f[i-1]*2)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
}
int main()
{
	init();
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof dp);
		memset(num,0,sizeof num);
		int n;scanf("%d",&n);
		for(int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			dp[i]=(2*dp[i-1]+sum[i-1]-num[x])%mod;
			num[x]=(num[x]+f[i])%mod;
		}
		printf("%lld\n",2ll*dp[n]);

	}
}