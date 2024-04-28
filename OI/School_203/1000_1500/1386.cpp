#include<cstdio>
#include<cstring>
#define min(a,b) ((a)>(b)?(b):(a))
int T,S,E,N,num[1005],tot,dis[20][205][205],ans[2][205];
void in_put()
{
	scanf("%d%d%d%d",&N,&T,&S,&E);
	memset(dis,0x3f,sizeof dis);
	for(int i=1,u,v,w;i<=T;++i)
	{
		scanf("%d%d%d",&w,&u,&v);
		if(!num[u])num[u]=++tot;
		if(!num[v])num[v]=++tot;
		dis[0][num[u]][num[v]]=w;
		dis[0][num[v]][num[u]]=w;
	}
}
void init()
{
	for(int t=1;t<20;++t)
		for(int i=1;i<=tot;++i)
			for(int j=1;j<=tot;++j)
				for(int k=1;k<=tot;++k)
					dis[t][i][j]=min(dis[t][i][j],dis[t-1][i][k]+dis[t-1][k][j]);
}
void Multi()
{
	memset(ans[0],0x3f,sizeof ans[0]);
	int cur=0;ans[0][num[S]]=0;
	for(int t=0;t<20;++t)
	{
		if(N&(1<<t))
		{
			memset(ans[cur^=1],0x3f,sizeof ans[0]);
			for(int i=1;i<=tot;++i)
				for(int j=1;j<=tot;++j)
					ans[cur][i]=min(ans[cur][i],ans[cur^1][j]+dis[t][i][j]);
		}

	}
	printf("%d\n",ans[cur][num[E]]);
}
int main()
{
	in_put();init();Multi();
}