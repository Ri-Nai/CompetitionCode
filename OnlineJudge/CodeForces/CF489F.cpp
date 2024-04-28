#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=505;
int n,m,mod,A[maxn][maxn],cnt[maxn];
LL dp[maxn][maxn];
int main()
{
	scanf("%d%d%d",&m,&n,&mod);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%1d",&A[i][j]),cnt[j]+=A[i][j];
	int s1=0,s2=0;
	for(int i=1;i<=m;++i)
		if(cnt[i]==0)++s2;
		else if(cnt[i]==1)++s1;
	dp[s1][s2]=1;
	for(int i=n+1;i<=m;++i)
		for(int j=0;j<=m;++j)
		{
			int k=(m-i+1)*2-j*2;
			if(k<0||k>m)continue;
			if(j>=1)(dp[k][j-1]+=dp[k][j]*j*k%mod)%=mod;
			if(j>=2)(dp[k+2][j-2]+=dp[k][j]*(j-1)*j/2%mod)%=mod;
			if(k>=2)(dp[k-2][j]+=dp[k][j]*(k-1)*k/2%mod)%=mod;
		}
	printf("%lld\n",dp[0][0]);
}