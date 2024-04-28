#include<cstdio>
#include<cstring>
#include<algorithm>
int n,w,Box,Group,C,V,dp[(int)1e6+5],tmp[(int)1e6+5];
void solve()
{
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&Box,&Group);
		for(int j=Box;j<=w;j++)
			tmp[j]=dp[j-Box];
		for(int j=1;j<=Group;++j)
		{
			scanf("%d%d",&C,&V);
			for(int k=w;k>=C+Box;--k)
				tmp[k]=std::max(tmp[k],tmp[k-C]+V);
		}
		for(int j=Box;j<=w;++j)
			dp[j]=std::max(dp[j],tmp[j]);
	}
	printf("%d\n",dp[w]);
}
int main()
{
	while(~scanf("%d%d",&n,&w))solve();
}