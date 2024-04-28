#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5;
bool vis[N];
int n,m,stk[N],top,low[N],dfn[N],num,blg[N],ans;
int head[N],to[M],nxt[M],sz[N],in[N],tot,blk,is;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void Tarjan(int u)
{
	int v;
	dfn[u]=low[u]=++num;
	stk[++top]=u;vis[u]=1;
	for(int i=head[u];v=to[i];i=nxt[i])
		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		++blk;do
			v=stk[top--],vis[v]=0,++sz[blg[v]=blk];
		while(v!=u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),Add(u,v);
	for(int i=1;i<=n;++i)
		if(!dfn[i])Tarjan(i);
	for(int u=1,v;u<=n;++u)
		for(int i=head[u];v=to[i];i=nxt[i])
			if(blg[u]!=blg[v])++in[blg[u]];
	for(int i=1;i<=blk;++i)
		if(!in[i])ans=sz[i],++is;
	printf("%d\n",is==1?ans:0);
}