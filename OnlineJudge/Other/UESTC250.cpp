#include<cstdio>
#include<cstring>
int dp[20][20][2],A[20];
inline int abs(int x){return x>0?x:-x;}
int dfs(int pos,int pre,bool lmt,bool first)
{
	if(pos==0)return 1;
	if(!lmt&&~dp[pos][pre][first])return dp[pos][pre][first];
	int Up=lmt?A[pos]:9,res=0;
	for(int i=0;i<=Up;++i)
	{
		if(first||abs(i-pre)>=2)
			res+=dfs(pos-1,i,lmt&&i==Up,first&&i==0);
	}
	if(!lmt)dp[pos][pre][first]=res;
	return res;
}
int solve(int x)
{
	int len=0;
	while(x)A[++len]=x%10,x/=10;
	int res=dfs(len,0,1,1);
//	printf("%d\n",res);
	return res;
}
int main()
{
	memset(dp,-1,sizeof dp);int x,y;
	while(~scanf("%d%d",&x,&y))
		printf("%d\n",solve(y)-solve(x-1));
}