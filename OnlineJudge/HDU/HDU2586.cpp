#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
int son[maxn],sz[maxn],dep[maxn],fa[maxn],top[maxn],dis[maxn],n,m;
int head[maxn],to[maxn<<1],nxt[maxn<<1],W[maxn<<1],tot;
inline void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	W[tot]=w;to[tot]=v;
	head[u]=tot;
}
void dfs(int u,int f,int d,int w)
{
	son[u]=0;dep[u]=d;sz[u]=1;
	fa[u]=f;dis[u]=w;
	for(int i=head[u];~i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dfs(v,u,d+1,w+W[i]);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int f,int tp)
{
	top[u]=tp;
	if(son[u])_dfs(son[u],u,tp);
	for(int i=head[u];~i;i=nxt[i])
	{
		int &v=to[i];
		if(v==son[u]||v==f)continue;
		_dfs(v,u,v);
	}
}
int LCA(int u,int v)
{
	while(top[u]^top[v])
		if(dep[top[u]]>=dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	return dep[u]<dep[v]?u:v;
}
inline int Dis(int u,int v)
{
	int t=LCA(u,v);
	return dis[u]-dis[t]+dis[v]-dis[t];
}
void solve()
{
	scanf("%d%d",&n,&m);tot=0;
	memset(head,-1,sizeof head);
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),
		Add(u,v,w),Add(v,u,w);
	dfs(1,0,1,0);_dfs(1,0,1);
	for(int u,v;m--;)
		scanf("%d%d",&u,&v),printf("%d\n",Dis(u,v));
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}