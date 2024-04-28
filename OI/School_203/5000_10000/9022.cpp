#include<cstdio>
#include<cstring>
#include<algorithm>
int tot[13],dp[1<<12][505];
int n,m,A[12][12],Bit[1<<12];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve()
{
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	dp[0][0]=1;int K=(1<<n)-1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&A[i][j]);
	for(int i=0;i<K;++i)
		for(int j=0;j<n;++j)if(!(1<<j&i))
			for(int k=0;k<=m;++k)
				dp[1<<j|i][std::min(m,k+A[j][Bit[i]])]+=dp[i][k];
	int way=dp[K][m];
	if(way)
	{
		int g=gcd(tot[n],way);
		printf("%d/%d\n",tot[n]/g,way/g);
	}
	else puts("No solution");
}
int main()
{
	int T;scanf("%d",&T);tot[0]=1;
	for(int i=1;i<=12;++i)tot[i]=tot[i-1]*i;
	for(int i=1;i<4096;++i)Bit[i]=Bit[i>>1]+(i&1);
	while(T--)solve();
}