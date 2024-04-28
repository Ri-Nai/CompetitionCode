#include<cstdio>
#include<algorithm>
const int maxn=205;
int A[maxn],n;
long long ans,dp[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),
		A[i+n]=A[i];
	for(int l=2;l<=n;++l)
		for(int i=1,j=l;j<2*n;++i,++j)
		{
			for(int k=i;k<j;++k)
				dp[i][j]=std::max(dp[i][j],dp[i][k]+dp[k+1][j]+1ll*A[i]*A[k+1]*A[j+1]);
			if(l==n)ans=std::max(dp[i][j],ans);
		}
	printf("%lld\n",ans);

}