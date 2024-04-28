#include<bits/stdc++.h>
using namespace std;
const int N=505,inf=0x3f3f3f3f;
int n,m,X,Y,id,mx,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char s[N][N],d[]={'U','R','D','L'};
bool vis[N][N][4];
bool pd(int x,int y)
{
	return x>=1&&y>=1&&x<=n&&y<=m;
}
int dfs(int x,int y,int d)
{
	//if(!pd(x,y))return 0;
	if(vis[x][y][d])return inf;
	vis[x][y][d]=1;
	int xx=x+dx[d],yy=y+dy[d];
	if(!pd(xx,yy))return 1;
	if(s[xx][yy]=='C')return 1;
	if(s[xx][yy]=='.')return dfs(xx,yy,d)+1;
	if(s[xx][yy]=='/')return dfs(xx,yy,d^1)+1;
	if(d==0)return dfs(xx,yy,3)+1;
	if(d==3)return dfs(xx,yy,0)+1;
	if(d==1)return dfs(xx,yy,2)+1;
	return dfs(xx,yy,1)+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	scanf("%d%d",&X,&Y);
	for(int i=0;i<4;++i)
	{
		memset(vis,0,sizeof vis);
		int now=dfs(X,Y,i);
		if(now>mx)mx=now,id=i;
	}
	putchar(d[id]);puts("");
	if(mx>=inf)puts("Voyager");
	else printf("%d\n",mx);
}