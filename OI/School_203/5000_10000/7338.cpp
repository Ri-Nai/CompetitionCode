#include<bits/stdc++.h>
using namespace std;
int id[8][8],kkid[5],ed[8],
dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool mark[64][64][64][64];
struct node
{
	int x[5],y[5],step;
}First;
bool judge(node A)
{
	int tmp[9]={};
    for(int i=1;i<=4;++i)tmp[A.y[i]]+=(1<<A.x[i]);
    for(int i=0;i<8;++i)if(tmp[i]!=ed[i])return 0;
    return 1;
}
inline bool pd(const int &x,const int &y)
{
	return x>=0&&y>=0&&x<8&&y<8;
}
void bfs()
{
	queue<node>Q;First.step=0;
	Q.push(First);
	while(!Q.empty())
	{
		node N=Q.front();Q.pop();
		for(int i=1;i<=4;++i)
		{
			int tx[5],ty[5],pid[5];
			for(int j=1;j<=4;++j)
				if(i!=j)
					tx[j]=N.x[j],ty[j]=N.y[j],
					pid[j]=id[tx[j]][ty[j]];
			for(int j=0;j<4;++j)
			{
				int xx=N.x[i]+dx[j],yy=N.y[i]+dy[j];
				if(!pd(xx,yy))continue;

				bool flag=1;
				for(int k=1;k<=4;++k)
					if(i!=k&&id[xx][yy]==pid[k])
						{flag=0;break;}

				if(!flag)xx+=dx[j],yy+=dy[j];
				if(!pd(xx,yy))continue;flag=1;
				for(int k=1;k<=4;++k)
					if(i!=k&&id[xx][yy]==pid[k])
						{flag=0;break;}

				if(!flag)continue;
				pid[i]=id[xx][yy];tx[i]=xx;ty[i]=yy;

				if(mark[pid[1]][pid[2]][pid[3]][pid[4]])continue;
				mark[pid[1]][pid[2]][pid[3]][pid[4]]=1;

				node New=(node){{0,tx[1],tx[2],tx[3],tx[4]},{0,ty[1],ty[2],ty[3],ty[4]},N.step+1};
				if(judge(New)){puts("YES");return;}
				if(New.step<8)Q.push(New);
			}
		}
	}
	puts("NO");
}
int main()
{
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
			id[i][j]=i*8+j;
	for(int i=1;i<=4;++i)
	{
		scanf("%d%d",&First.x[i],&First.y[i]);
		--First.x[i],--First.y[i];
	}
	for(int i=1,x,y;i<=4;++i)
	{
		scanf("%d%d",&x,&y);
		--x,--y;
		kkid[i]=id[x][y];
		ed[y]+=(1<<x);
	}
	if(judge(First))puts("YES");
	else bfs();
}