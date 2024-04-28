#include<bits/stdc++.h>
using namespace std;
#define ToMax(a,b) (a<(b)&&(a=b))
const int N=505,M=1e5+5;
int n,A[N],sum,dp[2][M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),sum+=A[i];
	memset(dp[0],-0x3f,sizeof dp[0]);
	int cur=0;dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		cur^=1;
		memset(dp[cur],-0x3f,sizeof dp[cur]);
		for(int j=0;j<=sum;++j)
		{
			if(dp[cur^1][j]<0)continue;
			ToMax(dp[cur][j],dp[cur^1][j]);
			if(j<=sum-A[i])ToMax(dp[cur][j+A[i]],dp[cur^1][j]);
			if(j>=A[i])ToMax(dp[cur][j-A[i]],dp[cur^1][j]+A[i]);
			else ToMax(dp[cur][A[i]-j],dp[cur^1][j]+j);
		}
	}
	if(dp[cur][0]>0)printf("%d\n",sum-dp[cur][0]);
	else puts("0");
}
