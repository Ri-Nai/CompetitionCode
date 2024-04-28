#include<cstdio>
#include<cstring>
int dp[12][2],a[12];
int dfs(int pos,bool pre,bool lmt)
{
	if(pos==0)return 1;
	if(!lmt&&~dp[pos][pre])return dp[pos][pre];
	int Up=lmt?a[pos]:9,res=0;
	for(int i=0;i<=Up;++i)
	{
		if(i==4)continue;
		if(pre&&i==2)continue;
		res+=dfs(pos-1,i==6,lmt&&i==Up);
	}
	if(!lmt)dp[pos][pre]=res;
	return res;
}
int solve(int x)
{
	if(x==0)return 1;int len=0;
	while(x)a[++len]=x%10,x/=10;
	return dfs(len,0,1);
}
int main()
{

	int x,y;memset(dp,-1,sizeof dp);
	while(scanf("%d%d",&x,&y)&&x&&y)printf("%d\n",solve(y)-solve(x-1));
}