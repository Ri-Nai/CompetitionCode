#include<cstdio>
#include<cstring>
long long dp[20][20];
int a[20];
long long dfs(int pos,int pre,bool lmt)
{
	if(pos==0)return 1;
	if(!lmt&&~dp[pos][pre])return dp[pos][pre];
	int Up=lmt?a[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
	{
		if(pre==4&&i==9)continue;
		res+=dfs(pos-1,i,lmt&&i==Up);
	}
	if(!lmt)dp[pos][pre]=res;
	return res;
}
long long solve()
{
	long long x,tmp;scanf("%lld",&x);
	tmp=x;int len=0;
	while(x)a[++len]=x%10,x/=10;
	return tmp-dfs(len,0,1)+1;
}
int main()
{
	memset(dp,-1,sizeof dp);
	int T;scanf("%d",&T);
	while(T--){printf("%lld\n",solve());}
}
