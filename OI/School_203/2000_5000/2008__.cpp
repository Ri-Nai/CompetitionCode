#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ToMin(a,b) ((b<a)&&(a=b))
const int n=9,m=512,p=8,inf=0x3f3f3f3f;
int dp[n][n][m][p][2];
char s[n][n];
int main()
{
	memset(dp,inf,sizeof dp);
	FOR(i,0,n)
	{
		scanf("%s",s[i]);
		FOR(j,0,n)s[i][j]^=48;
	}
	FOR(i,0,n)
	{
		if(i)
		{
			if(i==3|i==6)FOR(j,0,m)
			{
				if(dp[i-1][8][j][0][0]^inf)
					ToMin(dp[i][0][j][0][0],  dp[i-1][8][j][0][0]+ s[i][0]),
					ToMin(dp[i][0][j^1][1][1],dp[i-1][8][j][0][0]+!s[i][0]);
			}
			else FOR(k,0,p)FOR(j,0,m)
			{
				if(dp[i-1][8][j][k][0]^inf)
					ToMin(dp[i][0][j][k][0],    dp[i-1][8][j][k][0]+ s[i][0]),
					ToMin(dp[i][0][j^1][k^1][1],dp[i-1][8][j][k][0]+!s[i][0]);
			}
		}
		else dp[0][0][0][0][0]=s[0][0],dp[0][0][1][1][1]=!s[0][0];
		FOR(l,1,n)FOR(j,0,m)FOR(k,0,p)FOR(r,0,2)if(dp[i][l-1][j][k][r]^inf)
			ToMin(dp[i][l][j][k][r],dp[i][l-1][j][k][r]+s[i][l]),
			ToMin(dp[i][l][j^1<<l][k^1<<l/3][r^1],dp[i][l-1][j][k][r]+!s[i][l]);
	}
	printf("%d\n",dp[8][8][0][0][0]);
}