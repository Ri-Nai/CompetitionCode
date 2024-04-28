#include<cstdio>
#include<vector>
#include<cstring>
const int maxn=105,inf=-0x3f3f3f3f;
int dp[maxn/5][maxn*maxn],n,m,K,ans,flag;
inline long long max(const long long &a,const long long &b){return a>b?a:b;}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&K))
	{
		std::vector<int>B[15],C[15];
		memset(dp,inf,sizeof dp);
		memset(dp[0],0,sizeof dp);
		ans=inf,flag=0;
		for(int i=1,id,b,c;i<=n;++i)
			scanf("%d%d%d",&id,&b,&c),
			B[id].push_back(b),
			C[id].push_back(c);
		for(int i=1;i<=K;++i)
		{
			if(B[i].empty())flag=1;
			for(int j=0;j<B[i].size();++j)
				for(int k=m;k>=B[i][j];--k)
					dp[i][k]=max(dp[i][k],dp[i][k-B[i][j]]+C[i][j]),
					dp[i][k]=max(dp[i][k],dp[i-1][k-B[i][j]]+C[i][j]);
		}
		if(dp[K][m]<0)flag=1;
		if(flag)puts("Impossible");
		else printf("%d\n",dp[K][m]);
	}
}