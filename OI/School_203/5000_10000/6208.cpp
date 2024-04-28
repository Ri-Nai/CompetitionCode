#include<bits/stdc++.h>
using namespace std;
#define R register
const int N=2005,M=N*N;
char s[N];bitset<N>Can[N];bool vis[N],mark[N][N];
int n,low[N],dfn[N],num,blk,sz[N],blg[N],stk[N],top,ans;
struct Link
{
	int head[N],to[M],nxt[M],tot;
	Link(){tot=0;memset(head,0,sizeof head);}
	void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
}A,B;
void Tarjan(int u)
{
	int v;
	dfn[u]=low[u]=++num;
	stk[++top]=u;vis[u]=1;
	for(R int i=A.head[u];v=A.to[i];i=A.nxt[i])
		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		++blk;do
			v=stk[top--],++sz[blg[v]=blk],
			vis[v]=0,Can[blk].set(v);
		while(v!=u);
	}
}
void dfs(int u)
{
	for(R int i=B.head[u],v;v=B.to[i];i=B.nxt[i])
	{
		if(!vis[v])vis[v]=1,dfs(v);
		Can[u]|=Can[v];
	}
	ans+=sz[u]*Can[u].count();
}
int main()
{
	scanf("%d",&n);
	for(R int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(R int j=1;j<=n;++j)
			if(s[j]^48)A.Add(i,j);
	}
	for(R int i=1;i<=n;++i)
		if(!dfn[i])Tarjan(i);
	for(R int u=1,v;u<=n;++u)
		for(R int i=A.head[u];v=A.to[i];i=A.nxt[i])
		{
			int &fu=blg[u],&fv=blg[v];
			if(fu!=fv&&!mark[fu][fv])
				B.Add(fu,fv),mark[fu][fv]=1;
		}
	memset(vis,0,sizeof vis);
	for(R int i=1;i<=blk;++i)
		if(!vis[i])vis[i]=1,dfs(i);
	printf("%d\n",ans);
}