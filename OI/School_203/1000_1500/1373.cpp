#include<cstdio>
#include<algorithm>
const int maxn=5e5+5;
int n,V,A[maxn],v[maxn],w[maxn],
val[maxn],weigh[maxn],tot,dp[maxn];
void init()
{
	for(int i=1;i<=n;++i)
	{
		int now=1,sum=A[i];
		//printf("%d %d\n",v[i],w[i]);
		while(now<=sum)
			val[++tot]=v[i]*now,
			weigh[tot]=w[i]*now,
			sum-=now,now<<=1;
		if(sum)val[++tot]=v[i]*sum,
			   weigh[tot]=w[i]*sum;
	}
}
void in_put()
{
	scanf("%d%d",&V,&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&A[i],&w[i],&v[i]);
	init();
}
int main()
{
	in_put();
	for(int i=1;i<=tot;++i)
		for(int j=V;j>=weigh[i];--j)
			dp[j]=std::max(dp[j],dp[j-weigh[i]]+val[i]);
	printf("%d\n",dp[V]);
}