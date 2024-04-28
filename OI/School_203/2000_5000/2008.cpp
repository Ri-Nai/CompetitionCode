#include<bits/stdc++.h>
using namespace std;
const int n=9,inf=0x3f3f3f3f;
int dp[1<<n][2][1<<3][n][n];//列行格
char s[n][n];
//格的三行为一周期,所以总会清掉的
//清不掉就是非法的
int dfs(int x,int y,int r,int c,int blk)
{
	if(y==n)
	{
		if(c)return inf;
		if(x%3==2&&blk)return inf;
		if(x==8)return r?inf:0;
		return dfs(x+1,0,r,c,blk);
	}
	int &now=dp[r][c][blk][x][y];
	if(~now)return now;
	return now=min(dfs(x,y+1,r^1<<y,c^1,blk^1<<y/3)+!s[x][y],dfs(x,y+1,r,c,blk)+s[x][y]);
}
int main()
{
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<n;++j)s[i][j]^=48;
	}
	printf("%d\n",dfs(0,0,0,0,0));
}