#include<cstdio>
#include<cstring>
long long dp[20][2000][20],A[20],x,y,K;
int Get(int LIS)
{
	int res=0;
	while(LIS)res+=LIS&1,LIS>>=1;
	return res;
}
int Update(int LIS,int num)
{
	for(int i=num;i<=9;++i)if(LIS&(1<<i))return ((LIS^(1<<i))|(1<<num));
	return LIS|(1<<num);
}
long long dfs(int pos,int LIS,bool lmt,bool first)
{
	if(!pos)return Get(LIS)==K;
	if(!lmt&&~dp[pos][LIS][K])return dp[pos][LIS][K];
	int Up=lmt?A[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
	{
		if(first&&!i)res+=dfs(pos-1,0,lmt&&i==Up,1);
		else res+=dfs(pos-1,Update(LIS,i),lmt&&i==Up,0);
	}
	if(!lmt)dp[pos][LIS][K]=res;
	return res;
}
long long solve(long long num)
{
	int len=0;long long res=0;
	while(num)A[++len]=num%10,num/=10;
	return dfs(len,0,1,1);
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	for(int i=1;i<=T;++i)
		scanf("%lld%lld%d",&x,&y,&K),
		printf("Case #%d: %lld\n",i,solve(y)-solve(x-1));
}