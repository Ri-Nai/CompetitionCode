#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ToMin(a,b) ((a==-1||b<a)&&(a=b));
const int n=9,m=512,p=8;
int dp[n][m][p],A[n],res[m],cnt[m],Bit[m];char s[n];
int main()
{
	memset(dp,-1,sizeof dp);
	FOR(i,0,n)
	{
		scanf("%s",s);
		FOR(j,0,n)A[i]=A[i]<<1|s[j]^48;
	}
	FOR(i,1,m)Bit[i]=(cnt[i]=cnt[i^i&-i]+1)&1;
	FOR(i,1,m)if(!Bit[i])
		dp[0][i][res[i]=Bit[i&7]|Bit[i>>3&7]<<1|Bit[i>>6&7]<<2]=cnt[i^A[0]];
	dp[0][0][0]=cnt[A[0]];
	FOR(i,1,n)
	{
		bool flag=i%3==0;
		if(flag)
		{
			FOR(j,0,m)if(~dp[i-1][j][0])FOR(k,0,m)if(!Bit[k])
				ToMin(dp[i][j^k][res[k]],dp[i-1][j][0]+cnt[k^A[i]]);
			continue;
		}
		FOR(l,0,p)FOR(j,0,m)if(~dp[i-1][j][l])FOR(k,0,m)if(!Bit[k])
			ToMin(dp[i][j^k][l^res[k]],dp[i-1][j][l]+cnt[k^A[i]]);
	}
	printf("%d\n",dp[8][0][0]);
}