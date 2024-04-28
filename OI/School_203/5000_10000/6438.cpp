#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=3e5+5;
bool vis[N],flag;
int in[N],n,m,stk[N],top,num,ans,
low[N],dfn[N],blg[N],blk,sz[N];
struct Link
{
	int tot,head[N],to[M],nxt[M];
	Link(){memset(head,0,sizeof head),tot=0;}
	inline void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
}A,B;
void Tarjan(int u)
{
	vis[u]=low[u]=dfn[u]=++num;stk[++top]=u;
	for(int i=A.head[u],v;v=A.to[i];i=A.nxt[i])
		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		int v;++blk;do
			++sz[blg[v=stk[top--]]=blk],vis[v]=0;
		while(u!=v);
	}
}
bool check(int u)
{
	if(flag||in[u]||sz[u]!=1)return 0;
	for(int i=B.head[u],v;v=B.to[i];i=B.nxt[i])
		if(in[v]==1)return 0;
	return flag=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),A.Add(u,v);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int u=1,v;u<=n;++u)
		for(int i=A.head[u];v=A.to[i];i=A.nxt[i])
			if(blg[u]!=blg[v])B.Add(blg[u],blg[v]),++in[blg[v]];
	for(int i=1;i<=blk;++i)
		ans+=!in[i]-check(i);
	printf("%f\n",1.0-1.0*ans/n);
}