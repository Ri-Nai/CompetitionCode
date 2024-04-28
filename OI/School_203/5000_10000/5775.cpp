#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1e6+5;
int n,w,B,G,C,V,dp[maxn],tmp[maxn];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&B,&G);
		for(int j=B;j<=w;++j)tmp[j]=dp[j-B];
		for(int j=1;j<=G;++j)
		{
			scanf("%d%d",&C,&V);
			for(int k=w;k>=C+B;--k)
				tmp[k]=std::max(tmp[k],tmp[k-C]+V);
		}
		for(int j=B;j<=w;++j)dp[j]=std::max(dp[j],tmp[j]);
	}
	printf("%d\n",dp[w]);
}