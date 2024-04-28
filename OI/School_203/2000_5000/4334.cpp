#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m,dp[N][15];
int main()
{
	for(int i=1;i<N;++i)
		dp[i][1]=dp[i-1][1]+i+1;
	for(int i=1;i<N;++i)
		for(int j=2;j<=10;++j)
		{
			int mn=0x3f3f3f3f;
			for(int k=1;k<=i;++k)
				mn=min(mn,dp[k-1][j-1]+dp[i-k][j]);
			dp[i][j]=mn+i+1;
		}
	while(~scanf("%d%d",&n,&m))
		printf("%.6f\n",1.0*dp[n][min(m,10)]/(n+1));
}