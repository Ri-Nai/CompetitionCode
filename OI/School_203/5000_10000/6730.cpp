#include<cstdio>
#include<cstring>
#define int short
#define EOR(i,u) for(int i=head[u],v;v=to[i];i=nxt[i])
const int N=505;
long long ans,way;
int dfn[N],Cut[N],low[N],num,vis[N];
int n,m,Cas,head[N],to[N],nxt[N],tot,T,CntC,CntP;
void ToMin(int &x,const int &y){y<x&&(x=y);}
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	u>n&&(n=u);v>n&&(n=v);
}
void Tarjan(int u,int f)
{
	bool flag=0;
	dfn[u]=low[u]=++num;
	EOR(i,u)if(v!=f)
	{
		if(!dfn[v])
		{
			Tarjan(v,u);ToMin(low[u],low[v]);
			if(!f&&flag||f&&low[v]>=dfn[u])Cut[u]=Cas;flag=1;
		}
		else ToMin(low[u],dfn[v]);
	}
}
void dfs(int u,int f)
{
	vis[u]=T;++CntP;
	EOR(i,u)if(v!=f&&vis[v]!=T)
		if(Cut[v]!=Cas)dfs(v,u);
		else ++CntC,vis[v]=T;
}
void solve()
{
	memset(vis,0,sizeof vis);
	memset(dfn,0,sizeof dfn);
	memset(head,0,sizeof head);
	n=0;ans=0;way=1;tot=0;num=0;
	for(int i=1,u,v;i<=m;++i)
		scanf("%hd%hd",&u,&v),Add(u,v),Add(v,u);
	Tarjan(1,0);T=0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i]||Cut[i]==Cas)continue;
		CntC=CntP=0;++T;dfs(i,0);
		if(!CntC)ans+=2,way*=1ll*CntP*(CntP-1)/2;
		else if(CntC==1)++ans,way*=CntP;
	}
	printf("Case %d: %lld %lld\n",Cas,ans,way);
}
signed main()
{
	while(scanf("%hd",&m),m)++Cas,solve();
}