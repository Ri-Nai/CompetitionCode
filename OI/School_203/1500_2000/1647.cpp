#include<bits/stdc++.h>
using namespace std;
#define ToMin(x,y) ((x>(y))&&(x=(y)))
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
const int N=555;
int n,m,A[N][N],dp[N][N],C[N][N],ans;
void solve(int l,int r)
{
	if(r==l+1)return (void)(dp[l][r]=A[l][r]);
	int mid=l+r>>1,lm=l+mid>>1,rm=mid+1+r>>1;
	solve(l,mid),solve(mid+1,r);
	FOR(k,l,lm)FOR(i,lm+1,mid)FOR(j,mid+1,r)
		ToMin(C[i][j],dp[k][i]+A[k][j]);
	FOR(k,lm+1,mid)FOR(i,l,lm)FOR(j,mid+1,r)
		ToMin(C[i][j],dp[i][k]+A[k][j]);
	FOR(k,mid+1,rm)FOR(i,l,mid)FOR(j,rm+1,r)
		ToMin(dp[i][j],dp[k][j]+C[i][k]);
	FOR(k,rm+1,r)FOR(i,l,mid)FOR(j,mid+1,rm)
		ToMin(dp[i][j],dp[j][k]+C[i][k]);
}
int main()
{
	scanf("%d",&n);n=1<<n;
	FOR(i,1,n)FOR(j,1,n)scanf("%d",&A[i][j]);
	memset(dp,0x3f,sizeof dp);
	memset(C ,0x3f,sizeof C );
	ans=dp[0][0];;;solve(1,n);
	FOR(i,1,n>>1)FOR(j,(n>>1)+1,n)
		ToMin(ans,dp[i][j]);
	printf("%d\n",ans);
}