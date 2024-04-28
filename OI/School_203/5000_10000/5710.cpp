#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=2020;
int n,m,dp[maxn][maxn],D[maxn],I[maxn];
char s[maxn],c;
int main()
{
	scanf("%d%d%s",&m,&n,s+1);
	for(int i=1;i<=m;++i)
	{
		char tmp[2];
		scanf("%s",tmp);
		scanf("%d%d",&I[tmp[0]],&D[tmp[0]]);
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i)dp[i][i]=0;
	for(int l=1;l<=n;++l)
	  	for(int i=1;i+l<=n;++i)
		{
			int j=i+l;
			if(s[i]==s[j])
				if(j-i==1)dp[i][j]=0;
				else dp[i][j]=dp[i+1][j-1];
			dp[i][j]=std::min(dp[i][j],dp[i+1][j]+std::min(D[s[i]],I[s[i]]));
			dp[i][j]=std::min(dp[i][j],dp[i][j-1]+std::min(D[s[j]],I[s[j]]));
		}
	printf("%d\n",dp[1][n]);
}