#include<bits/stdc++.h>
using namespace std;
const int N=105,inf=0x7f7f7f7f;
int n,L,A[N],C[N],dp[N*N][N];
int main()
{
	scanf("%d%d",&n,&L);
	L=min(L,n-L);
	int sum1=0,sum2=0;
	memset(dp,inf,sizeof dp);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),sum1+=A[i];
	for(int i=1;i<=n;++i)scanf("%d",&C[i]),sum2+=C[i];
	double ans=1e18;dp[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=sum1;j>=A[i];--j)
			for(int k=1;k<=L;++k)
				dp[j][k]=min(dp[j][k],dp[j-A[i]][k-1]+C[i]);
	for(int i=0;i<=10000;++i)
	{
		int res=dp[i][L];
        if(res==inf)continue;
        ans=min(ans,1.0*res/i/(sum1-i)*(sum2-res));
	}
	printf("%.3f\n",ans);
}