#include<cstdio>
#include<cstring>
long long dp[20][20][3000],A[20],x,y;
long long dfs(int pos,int pivot,int sum,bool lmt)
{
	if(!pos)return !sum;
	if(!lmt&&~dp[pos][pivot][sum])return dp[pos][pivot][sum];
	int Up=lmt?A[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
		res+=dfs(pos-1,pivot,sum+(pos-pivot)*i,lmt&&i==Up);
	if(!lmt)dp[pos][pivot][sum]=res;
	return res;
}
long long solve(long long num)
{
	if(num==-1)return 0;
	int len=0;long long res=0;
	while(num)A[++len]=num%10,num/=10;
	for(int i=1;i<=len;++i)
		res+=dfs(len,i,0,1);
	return res-len+1;
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	while(T--)scanf("%lld%lld",&x,&y),printf("%lld\n",solve(y)-solve(x-1));
}
