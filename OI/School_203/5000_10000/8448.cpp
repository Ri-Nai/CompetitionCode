#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,top[N],fa[N],son[N],sz[N],L[N],R[N],dep[N],num,RT;
int nxt[N],head[N],to[N],tot;
int x[N],y[N],c[N],ans1[N],ans2[N];
vector<int> Q[N];
struct BIT
{
	int C[N];
	void Add(int x,int y){while(x<=n)C[x]+=y,x+=x&-x;}
	int Sum(int x){int res=0;while(x)res+=C[x],x^=x&-x;return res;}
}T;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
void dfs(int u)
{
	sz[u]=1;son[u]=0;dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];dfs(v);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;L[u]=++num;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=son[u])_dfs(to[i],to[i]);
	R[u]=num;
}
int LCA(int u,int v)
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&fa[i]);
		if(!fa[i])RT=i;
		else Add(fa[i],i);
	}
	dfs(RT);_dfs(RT,RT);
	scanf("%d",&m);
	for(int i=1,k;i<=m;++i)
	{
		scanf("%d%d",&k,&x[i]);
		if(k==1)
		{
			scanf("%d%d",&y[i],&c[i]);
			c[i]=i-c[i];
			Q[max(c[i],1)].push_back(i);
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<Q[i].size();++j)
		{
			int &id=Q[i][j],lca=LCA(x[id],y[id]);
			ans1[id]=dep[x[id]]+dep[y[id]]-dep[lca]-dep[fa[lca]];
			ans2[id]=T.Sum(L[x[id]])+T.Sum(L[y[id]])-T.Sum(L[lca])-T.Sum(L[fa[lca]]);
		}
		if(!y[i])T.Add(L[x[i]],1),T.Add(R[x[i]]+1,-1);
	}
	for(int i=1;i<=m;++i)if(y[i])printf("%d %d\n",ans1[i],ans2[i]);
}