#include<cstdio> 
#include<bitset>
const int maxm=1e5+5,maxn=105;
std::bitset<maxm>dp;
int n,m,A[maxn],K[maxn],T[maxm],val[maxm],tot,cnt;
int main()
{
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		dp.reset();dp[0]=1;tot=0;cnt=0;
		for(int i=1;i<=n;++i)scanf("%d",&K[i]);
		for(int i=1;i<=n;++i)scanf("%d",&A[i]);
		for(int i=1;i<=n;++i)
		{
			int now=1,sum=A[i];
			while(now<=sum)
				val[++tot]=K[i]*now,
				sum-=now,now<<=1;
			if(sum)val[++tot]=K[i]*sum;
		}
		for(int i=1;i<=tot;++i)
			dp|=(dp<<val[i]);
		for(int i=1;i<=m;++i)
			if(dp[i])++cnt;
		printf("%d\n",cnt);
	}
}