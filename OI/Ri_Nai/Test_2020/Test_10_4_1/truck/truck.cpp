#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5,inf=0x3f3f3f3f;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
struct Edge
{
	int u,v,w;
	void read(){scanf("%d%d%d",&u,&v,&w);}
	bool operator <(const Edge &_)const{return w>_.w;}
}E[M];
int n,m,Q,bz[N][20],Mn[N][20],dep[N];
int nxt[M],to[M],W[M],head[N],tot,fa[N];
bool vis[N];
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
void Kruskal()
{
	for(int i=1;i<=m;++i)E[i].read();
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(E+1,E+m+1);
	for(int i=1;i<=m;++i)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		Add(u,v,w);Add(v,u,w);
		fa[fv]=fu;
	}
}
void dfs(int u,int f,int lstw)
{
	dep[u]=dep[f]+1;
	bz[u][0]=f;Mn[u][0]=lstw;
	for(int i=1;i<20;++i)
	{
		bz[u][i]=bz[bz[u][i-1]][i-1];
		Mn[u][i]=min(Mn[u][i-1],Mn[bz[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=nxt[i])
		if(to[i]^f)dfs(to[i],u,W[i]);
}
void Build_Tree()
{
	for(int i=0;i<20;++i)Mn[0][i]=inf;
	for(int i=1;i<=n;++i)
		if(!vis[find(i)])
			dfs(i,0,inf),vis[fa[i]]=1;
}
int LCA(int u,int v)
{
	if(fa[u]!=fa[v])return -1;
	if(dep[u]<dep[v])swap(u,v);
	int res=inf,step=dep[u]-dep[v];
	for(int i=0;i<20;++i)
		if(1<<i&step)
			res=min(res,Mn[u][i]),u=bz[u][i];
	if(u==v)return res;
	for(int i=19;~i;--i)
		if(bz[u][i]^bz[v][i])
			res=min(res,min(Mn[v][i],Mn[u][i])),u=bz[u][i],v=bz[v][i];
	res=min(res,min(Mn[v][0],Mn[u][0]));
	return res;
}
int main()
{
	// FILE("truck");
	cin>>n>>m;
	Kruskal();
	Build_Tree();
	cin>>Q;
	for(int i=1,u,v;i<=Q;++i)
		scanf("%d%d",&u,&v),
		printf("%d\n",LCA(u,v));
	FCLS();
}