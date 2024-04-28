#include<cstdio>
#include<cstring>
#define Fasdasd
#define cc const int&
const int maxn=105+5,inf=0x3f3f3f3f,
dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int dp[maxn][maxn],mp[maxn][maxn],m,n,ans=inf;
inline bool pd(cc x,cc y)
{
	return x<=n&&y<=n&&x>=1&&y>=1;
}
void dfs(cc x,cc y,cc sum,bool is)
{
	if(sum>=dp[x][y])return ;
	dp[x][y]=sum;
	if(x==y&&x==n)
	{
		if(sum<ans)ans=sum;
		return ;
	}
	for(int i=0;i<4;++i)
	{
		int xx=x+dx[i],
			yy=y+dy[i];
		if(pd(xx,yy))
		{
			if(mp[xx][yy])
			{
				if(mp[xx][yy]==mp[x][y])
					dfs(xx,yy,sum,0);
				else dfs(xx,yy,sum+1,0);
			}
			else
				if(!is)
					mp[xx][yy]=mp[x][y],
					dfs(xx,yy,sum+2,1),
					mp[xx][yy]=0;
		} 
	}
}
void pre()
{
	scanf("%d%d",&n,&m);
	memset(dp,0x3f,sizeof dp);
	for(int i=1,x,y,z;i<=m;++i)
		scanf("%d%d%d",&x,&y,&z),
		mp[x][y]=z+1;//1 red 2 yellow
}
void solve()
{
	pre();
	dfs(1,1,0,0);
	if(ans==inf)puts("-1");
	else printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
