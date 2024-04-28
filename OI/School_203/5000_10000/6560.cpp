#include<cstdio>
const int mod=1e9+7,maxm=1<<16;
int A[16][16],n,dp[maxm],sum[maxm],sonset;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&A[i][j]),++A[i][j];
	for(int i=0;i<(1<<n);++i)
	{
		sum[i]=1;
		for(int j=0;j<n;++j)if(i&(1<<j))
			for(int k=j+1;k<n;++k)if(i&(1<<k))
				sum[i]=1ll*sum[i]*A[j][k]%mod;
		dp[i]=sum[i];sonset=i^(i&(-i));
		for(int j=sonset;j;j=(j-1)&sonset)
			dp[i]=(dp[i]-1ll*dp[i^j]*sum[j]%mod+mod)%mod;
	}
	printf("%d\n",dp[(1<<n)-1]);
}