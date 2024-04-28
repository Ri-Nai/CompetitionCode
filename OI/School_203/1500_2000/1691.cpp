#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1505;
int n,f[N][N];
LL dp[N][N],ans=0x3f3f3f3f3f3f3f3f;
int main()
{
	memset(dp,0x3f,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&f[i][j]);
	dp[1][1]=0;
	for(int i=2;i<=n;++i)//i,j都为上次爬的位置
		for(int j=1;j<=i;++j)
			dp[i][j]=min(dp[i][j],dp[i-1][j]+f[i-1][i]),//反着爬
			dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+f[j][i]);//爬到这
	for(int i=1;i<=n;++i)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}