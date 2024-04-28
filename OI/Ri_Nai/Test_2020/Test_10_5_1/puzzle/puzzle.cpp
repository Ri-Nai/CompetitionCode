#include<bits/stdc++.h>
using namespace std;
const int N=35,dx[]={1,0,-1,0},dy[]={0,1,0,-1},inf=0x3f3f3f3f;
#define ID(x,y) ((x)*31+y)
bool mark[N][N];
int val[4][N*N][N*N],dis[4][N*N],n,m,L,R,q;
int Ex,Ey,Sx,Sy,Tx,Ty;
struct P
{
	int x,y,stp;
}Q[N*N],p;
struct W
{
	int x,y,d,stp;
	int id(){return ID(x,y);}
	bool operator <(const W &_)const
	{
		return stp>_.stp;
	}
};
inline bool pd(int x,int y)
{
	return x<1||x>n||y<1||y>m||!mark[x][y];
}
void bfs(int f,int Ex,int Ey,int dir)
{
	val[dir][f][f]=0;
	if(pd(Ex,Ey))return ;
	L=R=0;Q[++R]=(P){Ex,Ey,val[dir][f][ID(Ex,Ey)]=0};
	while(L<R)
	{
		p=Q[++L];
		for(int i=0;i<4;++i)
		{
			int xx=p.x+dx[i],yy=p.y+dy[i];
			if(pd(xx,yy)|val[dir][f][ID(xx,yy)]^inf)continue;
			P q=(P){xx,yy,val[dir][f][ID(xx,yy)]=p.stp+1};
			Q[++R]=q;
		}
	}
}
int DijkSPFA()
{
	if(Sx==Tx&&Sy==Ty)return 0;
	memset(dis,inf,sizeof dis);
	priority_queue<W>Q;
	for(int i=0;i<4;++i)
	{
		int xx=Sx+dx[i],yy=Sy+dy[i],
			w=val[i][ID(Sx,Sy)][ID(Ex,Ey)];
		if(pd(xx,yy))continue;
		if(w^inf)Q.push((W){Sx,Sy,i,w});
	}
	while(!Q.empty())
	{
		W u=Q.top();Q.pop();
		// Rn_3(u.x,u.y,u.stp);
		for(int i=0;i<4;++i)
		{
			int xx=u.x+dx[u.d],yy=u.y+dy[u.d];//swap white and chess
			if(xx==Tx&&yy==Ty)return u.stp+1;
			if(pd(xx+dx[i],yy+dy[i]))continue;//set the white at dir i
			W v=(W){xx,yy,i,u.stp+1+val[i][ID(xx,yy)][u.id()]};
			if(v.stp>=dis[i][v.id()])continue;
			dis[i][v.id()]=v.stp;
			Q.push(v);
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(val,inf,sizeof val);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&mark[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mark[i][j])
				for(int k=0;k<4;++k)
					bfs(ID(i,j),i+dx[k],j+dy[k],k);
	while(q--)
	{
		scanf("%d%d%d%d%d%d",&Ex,&Ey,&Sx,&Sy,&Tx,&Ty);
		printf("%d\n",DijkSPFA());
	}
}