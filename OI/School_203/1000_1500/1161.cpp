#include <cstdio>
#include <algorithm>
#define sq(x) ((x)*(x))
const int maxn=205;
int A[maxn],B[maxn],S[maxn],
n,tot,dp[maxn][maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(A[tot]!=x)A[++tot]=x;
		++B[tot];
	}
	for(int i=1;i<=tot;++i)
		S[i]=S[i-1]+B[i];
	for(int l=0;l<tot;++l)
		for(int i=1,j=1+l;j<=tot;++i,++j)
		{
			for(int k=0;k<=n-S[j];++k)
				dp[i][j][k]=dp[i][j-1][0]+sq(B[j]+k);
			for(int k=j-1;k>=i;--k)
				if(A[j]==A[k])for(int L=0;L<=n-S[j];++L)
					dp[i][j][L]=std::max(dp[i][j][L],dp[i][k][B[j]+L]+dp[k+1][j-1][0]);
			//printf("%d\n",dp[i][j][0]);
		}
	printf("%d\n",dp[1][tot][0]);

}