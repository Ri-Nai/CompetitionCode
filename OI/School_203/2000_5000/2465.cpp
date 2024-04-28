#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
const int N=2005,M=4e6+5,mod=1e9+7;char s[N];
int n,A[N][N],pw[M]={1},ans,tot,Sum[N][N],dp[N][N],C[N][N],inv=1;
// namespace Fw
	//int nt1[N][N],nt2[N][N],Sum[N][N];
	// inline int GetSum(int x1,int y1,int x2,int y2)
	// {
	// 	return Sum[x2][y2]-Sum[x1-1][y2]-Sum[x2][y1-1]+Sum[x1-1][y1-1];
	// }
	// FOR(i,1,n)FOR(j,1,n)Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+A[i][j];
	// FOR(i,1,n)FOR(j,1,n)nt1[j][i]=A[j][i]?nt1[j-1][i]:j;
	// FOR(i,1,n)DOR(j,n,1)nt2[j][i]=A[j][i]?nt2[j+1][i]:j;
	// if(A[1][n])Add(ans,pw[tot-1]);
void Getinv(int n,int p)
{
	for(;p;p>>=1,n=1ll*n*n%mod)
		if(p&1)inv=1ll*inv*n%mod;
}
inline void Add(int &x,int y)
{
	(x+=y)>=mod&&(x-=mod);
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)
	{
		scanf("%s",s+1);
		FOR(j,1,n)tot+=(A[i][j]=s[j]=='.'),Sum[i][j]=Sum[i][j-1]+A[i][j];
	}
	dp[0][0]=1;Getinv(2,mod-2);
	FOR(i,1,tot)pw[i]=(pw[i-1]<<1)%mod;
	FOR(i,1,n)FOR(j,0,n)
		C[i][j]=1ll*pw[Sum[i][j]]*pw[Sum[i][n]-Sum[i][j]]%mod;
	FOR(i,1,n)
	{
		FOR(j,0,n)
		{
			if(j)
			{
				if(A[i][j])
					dp[i][j]=1ll*dp[i-1][j-1]%mod*C[i][j]*inv%mod+1ll*dp[i-1][j]*C[i][j]%mod;
				Add(dp[i-1][j],dp[i-1][j-1]);
			}
			else dp[i][j]=1ll*dp[i-1][j]*C[i][j];
		}
	}
	FOR(i,0,n)Add(ans,dp[n][i]);
	printf("%d\n",ans);
}