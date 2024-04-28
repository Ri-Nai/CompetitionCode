#include<cstdio>
#include<cstring>
const int mod=1e9+7;
char A[200];
long long dp[200][12][2];
long long dfs(int pos,int pre,bool is,bool lmt,bool first)
{
	if(!pos)return 1;
	if(!lmt&&!first&&~dp[pos][pre][is])return dp[pos][pre][is];
	int Up=lmt?A[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
	{
		if(first)(res+=dfs(pos-1,i,is,lmt&&i==Up,first&&!i))%=mod;
		else if(is)
		{
			if(i>pre)(res+=dfs(pos-1,i,0,lmt&&i==Up,0))%=mod;
			else (res+=dfs(pos-1,i,1,lmt&&i==Up,0))%=mod;
		}
		else if(i>=pre)(res+=dfs(pos-1,i,0,lmt&&i==Up,0))%=mod;
	}
	if(!lmt&&!first)dp[pos][pre][is]=res;
	return res;
}
long long solve()
{
	int len=strlen(A+1);
	for(int i=1,j=len;i<=j;++i,--j)
	{
		A[i]-='0';if(i!=j)A[j]-='0';
		int t=A[i];A[i]=A[j];A[j]=t;
	}
	return (dfs(len,99,1,1,1)+mod-1)%mod;
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	for(int i=1;i<=T;++i)
		memset(A,0,sizeof A),scanf("%s",A+1),
		printf("%lld\n",solve());
}