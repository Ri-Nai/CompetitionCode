#include<bits/stdc++.h>
using namespace std;
int n,m,fx[4][2]={0,1,0,-1,1,0,-1,0};
struct point 
{
	int x,y,step;
}p,s,t,pp;
queue<point> q;
char c[505][505];
bool mark[505][505];
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",c[i]+1);
		getchar();
		//cout<<c[i]+1<<endl;
		for(int j=1;j<=m;++j)
		{
			if(c[i][j]=='S')s.x=i,s.y=j,mark[i][j]=1;
			if(c[i][j]=='T')t.x=i,t.y=j;
		}
	}
	
	q.push(s);
	while(!q.empty())
	{
		p.x=q.front().x;
		p.y=q.front().y;
		p.step=q.front().step;
		//cout<<p.x<<' '<<p.y<<endl;
		q.pop();
		if(p.x==t.x&&p.y==t.y)
		{
			cout<<p.step;
			return 0;
		}
		else
		{
			for(int i=0;i<4;++i)
			{
				pp.x=p.x+fx[i][0];
				pp.y=p.y+fx[i][1];
				pp.step=p.step+1;
				if(pp.x>=1&&pp.x<=n&&pp.y>=1&&pp.y<=m&&c[pp.x][pp.y]!='#'&&!mark[pp.x][pp.y])
					q.push(pp),mark[pp.x][pp.y]=1;
			}
		}
	}
	cout<<-1;
	
}