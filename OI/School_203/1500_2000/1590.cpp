#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mod=1e4+7;
char s[15][15];
bool mark[15][15];
inline bool check(const int &x,const int &y)
{
	if(x==0&&y==1)return 1;
	if(x==n+1&&y==m)return 1;
	return x>=1&&y>=1&&x<=n&&y<=m&&s[x][y]!='#'&&!mark[x][y];
}
int dfs(int x,int y)
{
	if(x==n+1&&y==m)return ++ans,0;
	mark[x][y]=1;
	check(x+1,y)&&dfs(x+1,y);
	check(x,y+1)&&dfs(x,y+1);
	check(x-1,y)&&dfs(x-1,y);
	check(x,y-1)&&dfs(x,y-1);
	mark[x][y]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	dfs(0,1);
	printf("%d\n",ans%mod);
}