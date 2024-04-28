#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=36501;
bool vis[N],mark[N],fly[N];
int n,m,stk[N],top,dfn[N],low[N],num,blk,blg[N],cook[N],mx,cnt;
int rd()
{
	int x=0,c=0;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
struct Link
{
	int head[N],to[N],nxt[N],tot;
	Link(){memset(head,0,sizeof head),tot=0;}
	void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
}A,B;
void Tarjan(int u)
{
	int v;vis[u]=stk[++top]=u;
	dfn[u]=low[u]=++num;
	for(int i=A.head[u];v=A.to[i];i=A.nxt[i])
		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
		else
		{
			if(vis[v])low[u]=min(low[u],dfn[v]);
			if(v==u)mark[v]=1;
		}
	if(low[u]==dfn[u])
	{
		++blk;int sz=0;do
			v=stk[top--],vis[v]=0,
			++sz,fly[blg[v]=blk]|=mark[v];
		while(u!=v);
		fly[blk]|=(sz>1);
	}
}
void dfs(int u)
{
	vis[u]=1;int v,res=0;
	if(u==blg[n])mark[u]=1,res=1;
	for(int i=B.head[u];v=B.to[i];i=B.nxt[i])
	{
		if(!vis[v])dfs(v);
		mark[u]|=mark[v];
		if(res<M&&mark[v])res+=cook[v];
		if(res>M)res=M;
	}
	cook[u]=res;
	if(fly[u]&&mark[u])cook[u]=M;
	mx=max(mx,cook[u]);
}
int main()
{
	n=rd()+1;m=rd();
	for(int i=1,u,v;i<=m;++i)
		u=rd(),v=rd(),A.Add(u,v);
	for(int i=1;i<=n;++i)
		if(!dfn[i])Tarjan(i);
	memset(mark,0,sizeof mark);
	for(int u=1,v;u<=n;++u)
		for(int i=A.head[u];v=A.to[i];i=A.nxt[i])
			if(blg[u]!=blg[v])B.Add(blg[u],blg[v]);
	for(int i=1;i<=blk;++i)
		if(!vis[i])dfs(i);
	if(mx==M)puts("zawsze");
	else printf("%d\n",mx);
	for(int i=1;i<n;++i)
		if(cook[blg[i]]==mx)++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<n;++i)
		if(cook[blg[i]]==mx)
			printf("%d ",i);
}