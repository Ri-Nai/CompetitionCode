#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout);
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ToMin(x,y) (x>(y))&&(x=y)
const int N=1e4+5,M=1e3+5,inf=0x3f3f3f3f;
int n,m,k,U[N],D[N],L[N],H[N],dp[2][N][M],is[N],pos;
bool flag=1;
int main()
{
	// FILE("bird");
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d%d",&U[i],&D[i]);
	for(int i=1,p;i<=k;++i)
		scanf("%d",&p),is[++p]=1,
		scanf("%d%d",&L[p],&H[p]),++L[p],--H[p];
	for(int i=1;i<=n+1;++i)
	{
		if(!is[i])L[i]=1,H[i]=m;
		is[i]+=is[i-1];
	}
	memset(dp,inf,sizeof dp);pos=n+1;
	for(int i=L[1];i<=H[1];++i)dp[0][1][i]=0;
	for(int i=1;flag&&i<=n;++i)
	{
		bool pd=0;
		for(int j=1;j<=H[i];++j)
		{
			int nxt=min(m,j+U[i-1]);
			ToMin(dp[1][i][nxt],dp[1][i][j]+1);
			if(j<L[i])continue;
			int now=min(dp[1][i][j],dp[0][i][j]);
			if(now==inf)continue;pd=1;
			int l=j-D[i],h=min(m,j+U[i]);
			if(l>0)ToMin(dp[0][i+1][l],now);
			ToMin(dp[1][i+1][h],now+1);
		}
		if(!pd)flag=0,pos=i;
	}
	int mn=inf;
	for(int i=L[n+1];i<=H[n+1];++i)
	{
		if(i-U[n]>=L[n+1])
			ToMin(dp[1][n+1][i],dp[1][n+1][i-U[n]]+1);
		int now=min(dp[1][n+1][i],dp[0][n+1][i]);
		ToMin(mn,now);
	}
	flag&=mn!=inf;
	printf("%d\n",flag);
	if(flag)printf("%d\n",mn);
	else printf("%d\n",is[max(0,pos-1)]);
	FCLS();
}
