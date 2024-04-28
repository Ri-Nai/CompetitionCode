#include<cstdio>
#include<cstring>
#define f(i,t,n) for(int i=(t);i<=(n);++i)
#define Fasda
const int maxn=1e5+56;
int n,a[maxn],b[maxn];
long long dp[maxn][3],ans;
inline int max(const int &a,const int &b)
{
	return a>b?a:b;
}
void solve()
{
	scanf("%d",&n);
	f(i,1,n)scanf("%d",&a[i]);
	f(i,1,n)scanf("%d",&b[i]);
	f(i,1,n)
	{
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1])+b[i];
	}
	for(int i=0;i<3;++i)
		ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
}
int main()
{
	#ifndef F
	freopen("basketball.in","r",stdin);
	freopen("basketball.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
3
1 2 9
10 1 1
19
*/
