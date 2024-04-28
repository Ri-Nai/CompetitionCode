#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=N<<1;
#define EOR(i,L,u) for(int i=L.head[u],v;v=L.to[i];i=L.nxt[i])
int n,m,top[N],fa[N],dep[N],son[N],sz[N],W[N],id[N],Re[N],ans[N],tot,C1[M],C2[M],cnt[N];
struct Link
{
	int head[N],to[M],nxt[M],tot;
	Link(){tot=0;memset(head,0,sizeof head);}
	void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
}A,B,C;
int rd()
{
	int t=0,c;while(!isdigit(c=getchar()));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
int LCA(int u,int v)
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct Que
{
	int u,v,lca,len;
	void read(int i)
	{
		u=rd();v=rd();
		len=dep[u]+dep[v]-(dep[lca=LCA(u,v)]<<1);
		if(dep[lca]+W[lca]==dep[u])--ans[lca];//减去重复的
		B.Add(v,i);C.Add(lca,i);++cnt[u];
	}
}Q[N];
void dfs(int u,int f)
{
	fa[u]=f;dep[u]=dep[f]+1;sz[u]=1;
	EOR(i,A,u)if(v^f)
	{
		dfs(v,u);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;Re[id[u]=++tot];
	if(son[u])_dfs(son[u],tp);
	EOR(i,A,u)if(v!=son[u]&&v!=fa[u])_dfs(v,v);
}
void dfs_(int u)
{
	//u->lca 上爬 lca->v下爬
	int c1=C1[W[u]+dep[u]],c2=C2[W[u]-dep[u]+n];//dfs做差
	EOR(i,A,u)if(v^fa[u])dfs_(v);
	C1[dep[u]]+=cnt[u];//起点的贡献
	EOR(i,B,u)++C2[Q[v].len-dep[Q[v].v]+n];//作为终点的贡献
	ans[u]+=C1[W[u]+dep[u]]-c1+C2[W[u]-dep[u]+n]-c2;
	EOR(i,C,u)--C1[dep[Q[v].u]],--C2[Q[v].len-dep[Q[v].v]+n];
}
int main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<n;++i)A.Add(u=rd(),v=rd()),A.Add(v,u);
	for(int i=1;i<=n;++i)W[i]=rd();dfs(1,0),_dfs(1,1);
	for(int i=1;i<=m;++i)Q[i].read(i);dfs_(1);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}
/*


*/
