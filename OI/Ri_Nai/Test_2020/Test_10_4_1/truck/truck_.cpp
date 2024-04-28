#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=4e5+5,inf=0x3f3f3f3f;
int n,m,Q,sz[N],fa[N],dis[N],bz[N][10],Mn[N][10],dep[N];
bool vis[N];
struct Edge
{
	int u,v,w;
	void read(){scanf("%d%d%d",&u,&v,&w);}
	bool operator <(const Edge &_)const{return w>_.w;}
}E[M];
int find(int u)
{
	return u==fa[u]?u:find(fa[u]);
}
int Find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
int nxt[N],to[N],W[N],head[N],tot;
void Add(int u,int v,int w)
{
    ++tot;
	nxt[tot]=head[u];
	to[tot]=v;
	W[tot]=w;
    head[u]=tot;
}
void dfs(int u,int f,int lstW)
{
	dep[u]=dep[f]+1;
	bz[u][0]=f;Mn[u][0]=lstW;
	for(int i=1;i<4;++i)
	{
		bz[u][i]=bz[bz[u][i-1]][i-1];
		Mn[u][i]=min(Mn[u][i-1],Mn[bz[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=nxt[i])
		dfs(to[i],u,W[i]);
}
int LCA(int u,int v)
{
	if(fa[u]!=fa[v])return -1;
	if(dep[u]<dep[v])swap(u,v);
	int res=inf,step=dep[u]-dep[v];
	for(int i=0;i<4;++i)
		if(1<<i&step)
			res=min(res,Mn[u][i]),u=bz[u][i];
	if(u==v)return res;
	for(int i=3;~i;--i)
		if(bz[u][i]^bz[v][i])
			res=min(res,min(Mn[v][i],Mn[u][i])),u=bz[u][i],v=bz[v][i];
	res=min(res,min(Mn[v][0],Mn[u][0]));
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)E[i].read();
	sort(E+1,E+m+1);
	for(int i=1;i<=m;++i)
	{
		int u=find(E[i].u),v=find(E[i].v);
		if(u==v)continue;
		if(sz[u]<sz[v])swap(u,v);
		fa[v]=u;sz[u]+=sz[v];
		Add(u,v,E[i].w);
	}
	for(int i=1;i<=n;++i)
		if(!vis[Find(i)])
			dfs(fa[i],0,inf),vis[fa[i]]=1;
	cin>>Q;
	for(int u,v;Q--;)
		scanf("%d%d",&u,&v),
		printf("%d\n",LCA(u,v));
}
