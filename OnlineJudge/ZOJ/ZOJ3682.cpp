#include<cstdio>
#include<cstring>
const int maxn=205,maxm=2e5+5,P=1e9+7;
int s1,s2,n,dp[maxm];
int main()
{
	while(~scanf("%d%d%d",&s1,&s2,&n))
	{
		memset(dp,0,sizeof dp);dp[0]=1;
		for(int i=1,v;i<=n;++i)
		{
			scanf("%d",&v);
			for(int j=s1;j>=0;--j)
			{
				if(j>=v)(dp[j]+=dp[j-v])%=P;
				if((v&1^1)&&j>=(v>>1))(dp[j]+=(dp[j-(v>>1)]))%=P;
			}
		}
		printf("%d\n",dp[s1]);
	}
}