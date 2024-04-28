#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
#define KOR(a,p) (a>>p)|(a<<p)
const int N=32,M=1e6+5,T=7;
int xx,yy,n,m,Can1[N][M],dp[2][N],Can2[T+1][N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&xx,&yy);--xx;--yy;
	FOR(i,0,n-1)FOR(j,0,n-1)
	{
		int kk;scanf("%d",&kk);
		if(kk<=T)Can2[kk][i]|=1<<j;
		else for(register int k=kk;k<=m;k+=kk)Can1[i][k]|=1<<j;
	}
	int cur=0,ans=0;dp[0][xx]=1<<yy;
	FOR(i,1,m)
	{
		FOR(j,1,T)if(i%j==0)
			FOR(k,0,n-1)Can1[k][i]|=Can2[j][k];
		FOR(j,0,n-1)
		{
			dp[cur^1][j]=0;
			if(j)		dp[cur^1][j]|=KOR(dp[cur][j-1],2);
			if(j<n-1)	dp[cur^1][j]|=KOR(dp[cur][j+1],2);
			if(j>1)		dp[cur^1][j]|=KOR(dp[cur][j-2],1);
			if(j<n-2)	dp[cur^1][j]|=KOR(dp[cur][j+2],1);
			dp[cur^1][j]&=Can1[j][i];
		}
		cur^=1;
	}
	FOR(i,0,n-1)FOR(j,0,n-1)
		if(1<<j&dp[cur][i])++ans;
	printf("%d\n",ans);
	FOR(i,0,n-1)FOR(j,0,n-1)
		if(1<<j&dp[cur][i])
			printf("%d %d\n",i+1,j+1);
}
/*
3 2
1 1
1 3 2
2 3 2
3 1 1
*/