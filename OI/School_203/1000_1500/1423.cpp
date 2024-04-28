#include<cstdio>
const int mod=1e6+7;
int n,m,A[105],dp[105];
int main()
{
	scanf("%d%d",&n,&m);dp[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=0;--j)
			for(int k=1;k<=A[i];++k)
				if(j-k>=0)dp[j]=(dp[j]+dp[j-k])%mod;
	printf("%d\n",dp[m]);
}