#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5,mod=1e9+7;
int dp[2][maxn][maxn],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	int cur=0;
	memset(dp[0],0,sizeof dp[0]);
	for(int i=1;i<=k;++k)
	{
		memset(dp[cur^=1],0,sizeof dp[0]);
		for(int j=1;j<=n;++j)
			for(int l=j;l<=n;l+=j)
			{
				dp[cur][l]+=dp[cur^1][j];
				if(dp[cur][l]>mod)dp[cur][l]-=mod;
			}
	}
}
