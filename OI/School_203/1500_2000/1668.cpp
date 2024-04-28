#include<bits/stdc++.h>
using namespace std;
const int N=505,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct node{int x,y,step;};
int n,ans[N*N],L[N][N],R[N][N],vis[N][N],id[N][N],cnt;
queue<node>Q;
bool pd(int x,int y)
{
	return x<=n&&y<=(n-1+(x&1))&&x>=1&&y>=1&&!vis[x][y];
}
inline void PUSH(int x,int y,int step)
{
	Q.push((node){x,y,step});
	vis[x][y]=1;
}
void bfs()
{
	memset(ans,-1,sizeof ans);
	Q.push((node){1,1,1});
	vis[1][1]=1;
	while(!Q.empty())
	{
		node p=Q.front();Q.pop();
		int x=p.x,y=p.y,step=p.step,k=x&1;
		ans[id[x][y]]=step;

		if(pd(x,y+1)&&R[x][y]==L[x][y+1])PUSH(x,y+1,step+1);
		if(pd(x,y-1)&&L[x][y]==R[x][y-1])PUSH(x,y-1,step+1);

		if(pd(x+1,y+1-k)&&R[x][y]==L[x+1][y+1-k])PUSH(x+1,y+1-k,step+1);
		if(pd(x-1,y+1-k)&&R[x][y]==L[x-1][y+1-k])PUSH(x-1,y+1-k,step+1);

		if(pd(x+1,y-k)&&L[x][y]==R[x+1][y-k])PUSH(x+1,y-k,step+1);
		if(pd(x-1,y-k)&&L[x][y]==R[x-1][y-k])PUSH(x-1,y-k,step+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int len=(n-1)+(i&1);
		for(int j=1;j<=len;++j)
			scanf("%d%d",&L[i][j],&R[i][j]),id[i][j]=++cnt;
	}
	bfs();
	for(int i=cnt;i;--i)
		if(~ans[i])return printf("%d\n",ans[i]),0;
}