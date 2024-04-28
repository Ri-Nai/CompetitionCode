#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
const int maxn=2e3+5;
const LL mod=(1ll<<31)-1;
LL dp[2][2005][2005],ans;
int A[maxn],n;
inline void Add(LL &A,const LL &B)
{
	A+=B;A%=mod;
}
int main()
{
	//printf("%lld\n",mod);
	scanf("%d",&n);
	for(int i=0;i<=n;++i)scanf("%d",&A[i]);
	if(A[0]>A[1])std::swap(A[0],A[1]);
	dp[1][A[0]][A[1]]=1;
	for(int i=2;i<=n;++i)
	{
		int cur=i&1,pre=cur^1;
		dp[cur][A[i]][A[i-1]]=0;
		dp[cur][A[i-1]][A[i]]=0;
		for(int j=1;j<=n+1;++j)
			dp[cur][j][A[i]]=dp[cur][A[i]][j]=0;
		if(A[i]>A[i-1])
		{
			for(int j=1;j<=A[i-1];++j)
				Add(dp[cur][j][A[i]],dp[pre][j][A[i-1]]);
			for(int j=A[i-1]+1;j<=A[i];++j)
				Add(dp[cur][A[i-1]][A[i]],dp[pre][A[i-1]][j]);
			for(int j=A[i]+1;j<=n+1;++j)
				Add(dp[cur][A[i-1]][A[i]],dp[pre][A[i-1]][j]),
				Add(dp[cur][A[i]][j],dp[pre][A[i-1]][j]);
		}
		else
		{	
			for(int j=1;j<=A[i];++j)
				Add(dp[cur][j][A[i]],dp[pre][j][A[i-1]]),
				Add(dp[cur][A[i]][A[i-1]],dp[pre][j][A[i-1]]);
			for(int j=A[i]+1;j<=A[i-1];++j)
				Add(dp[cur][A[i]][A[i-1]],dp[pre][j][A[i-1]]);
			for(int j=A[i-1]+1;j<=n+1;++j)
				Add(dp[cur][A[i]][j],dp[pre][A[i-1]][j]);
		}
	}
	for(int i=1;i<=n+1;++i)
		Add(ans,dp[n&1][i][A[n]]+dp[n&1][A[n]][i]);
	printf("%lld\n",ans);
}