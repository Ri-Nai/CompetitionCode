#include<cstdio>
#include<cstring>
int dp[40][40][40],A[40];
inline int abs(int x){return x>0?x:-x;}
int dfs(int pos,int num0,int num1,bool lmt,bool first)
{
	if(pos==0)return num0>=num1;
	if(!lmt&&~dp[pos][num0][num1])return dp[pos][num0][num1];
	int Up=lmt?A[pos]:1,res=0;
	for(int i=0;i<=Up;++i)
	{
		if(first)res+=dfs(pos-1,num0,num1+i,lmt&&i==Up,first&&!i);
		else  res+=dfs(pos-1,num0+!i,num1+i,lmt&&i==Up,first&&!i);
	}
	if(!lmt)dp[pos][num0][num1]=res;
	return res;
}
int solve(int x)
{
	int len=0;
	while(x)A[++len]=x&1,x>>=1;
	int res=dfs(len,0,0,1,1);
//	printf("%d\n",res);
	return res;
}
int main()
{
	memset(dp,-1,sizeof dp);int x,y;
	while(~scanf("%d%d",&x,&y))
		printf("%d\n",solve(y)-solve(x-1));
}