#include<cstdio>
#include<cstring>
int dp[2][20][10][20],A[20];
int dfs(int id,int pos,int pre,bool lmt,int num,bool first)
{
	if(pos==0)return num==0;
	if(!lmt&&~dp[id][pos][pre][num])return dp[id][pos][pre][num];
	int Up=lmt?A[pos]:9,res=0;
	for(int i=0;i<=Up;++i)
	{
		if(id&&pre==1&&i==3)continue;
		res+=dfs(id,pos-1,i,lmt&&i==Up,(num*10+i)%13,first&&!i);
	}
	if(!lmt)dp[id][pos][pre][num]=res;
	return res;
}
int solve(int x)
{
	int len=0;
	while(x)A[++len]=x%10,x/=10;
	return dfs(0,len,0,1,0,0)-dfs(1,len,0,1,0,0);
}
int main()
{
	memset(dp,-1,sizeof dp);int x;
	while(~scanf("%d",&x))printf("%d\n",solve(x));
}
