#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,mod,dp[N][N],ans;
int main()
{
	dp[2][2]=1;
	scanf("%d%d",&n,&mod);
	for(int i=3;i<=n;++i)
		for(int j=1;j<=i;++j)
			dp[i][j]=(dp[i][j-1]+dp[i-1][i-j+1])%mod;
	for(int i=1;i<=n;++i)
		ans=(ans+dp[n][i])%mod;
	printf("%d\n",(ans<<1)%mod);
}