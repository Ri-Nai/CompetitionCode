#include<cstdio>
#include<cstring>
#include<algorithm>
#define F
const int maxn=506,maxm=105;
int dp[maxn][maxm],sum[maxn][maxn],n,m,t[maxn];
//dp 第i个人等了j时间(上一辆车)的最小等待时间和 
void pre()
{
	t[0]=-2e9;//第0个人不需要等待 所以与后人的差应越小越好 
	scanf("%d%d",&n,&m);
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i)
		scanf("%d",&t[i]);
	std::sort(t+1,t+n+1);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=i;k<j;++k)
				sum[i][j]+=t[j]-t[k];
	//sum 预处理以i为起点 j为终点的区间内 取j为出发点 需要额外付出的等待时间
	for(int i=0;i<=m;++i)
		dp[0][i]=0,//初始化 
		dp[1][i]=i;//第1个人只需要等待自己的时间 
}
void solve()
{
	pre();
	for(int i=2;i<=n;++i)//0 1 已经处理过了 只需从二开始
						//这一辆车的最后一个人 
		for(int j=0;j<i;++j)//上一辆车的最后一个人 
			for(int k=0;k<=m;++k)//等上一辆车等了k时间
			{
				int now=t[j]-t[i]+m+k;
				if(now<0)now=0;
				//printf("%d\n",now);
				//printf("%d %d\n",i,dp[i][now]);
				dp[i][now]=std::min(dp[i][now],dp[j][k]+sum[j+1][i]+(i-j)*now);
				//printf("%d\n",dp[i][now]);
			}
	int ans=2e9;
	for(int i=0;i<=m;++i)
		//printf("%d %d\n",ans,dp[n][i]),
		ans=std::min(dp[n][i],ans);
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
5 1
3 4 4 3 5
5 5
1 3 1 5 5
*/
