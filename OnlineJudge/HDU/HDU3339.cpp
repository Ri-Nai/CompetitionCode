#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=105;
int n,m,W[maxn],dis[maxn][maxn],tot,sum,dp[(int)1e6+5];
void in_put()
{
	scanf("%d%d",&n,&m);sum=tot=0;
	memset(dis,0x3f,sizeof dis);dis[0][0]=0;
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&u,&v,&w),
		dis[u][v]=std::min(dis[u][v],w),
		dis[v][u]=std::min(dis[v][u],w);
	for(int i=1;i<=n;++i)scanf("%d",&W[i]),dis[i][i]=0,tot+=W[i];
	for(int k=0;k<=n;++k)
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i)if(dis[i][0]<0x3f3f3f3f)sum+=dis[i][0];
}
void solve()
{
	in_put();
	memset(dp,0,sizeof dp);
	//	puts("aaa");printf("%d\n", sum);
	for(int i=1;i<=n;++i)
		for(int j=sum;j>=dis[i][0];--j)
			dp[j]=std::max(dp[j],dp[j-dis[i][0]]+W[i]);
	for(int i=1;i<=sum;++i)
		if(dp[i]*2>tot)
		{
			printf("%d\n",i);
			return ;
		}
	puts("impossible");
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}