#include<cstdio>
#include<algorithm>
const int maxn=1e4+5;
int dp[2][maxn],n,m,A[maxn];
inline int x2(const int &x){return x*x;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	std::sort(A+1,A+n+1);
	for(int i=1;i<=m;++i)
		for(int j=i+1;i<=n;++i)
			dp[i&1][j]=std::min(dp[i&1][j]+x2(A[i]-A[i-1]),dp[i&1^1][j-1]);
	printf("%d\n",dp[m&1][n]);
}