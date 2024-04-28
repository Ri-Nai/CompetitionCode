#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=N<<1;
int nxt[M],to[M],head[N],tot;
int Head[N],U[N],V[N],W[N],NT[N];
int n,m,L[N],R[N],fa[N],top[N],dep[N],sz[N],son[N],C[N],dp[N],sum[N];
void _Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void ADD(int f,int u,int v,int w)
{
	NT[++tot]=Head[f];
	U[tot]=u;V[tot]=v;
	W[Head[f]=tot]=w;
}
void dfs(int u,int f)
{
	sz[u]=1;fa[u]=f;dep[u]=dep[f]+1;
	for(int i=head[u],v;v=to[i];i=nxt[i])
	{
		if(v==f)continue;dfs(v,u);
		if(sz[v]>sz[son[u]])
			son[u]=v;sz[u]+=sz[v];
	}
}
void _dfs(int u,int tp)
{
	L[u]=++tot;top[u]=tp;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u],v;v=to[i];i=nxt[i])
		if(v!=fa[u]&&v!=son[u])_dfs(v,v);
	R[u]=tot;
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
void Solve(int u,int f)
{
	for(int i=head[u],v;v=to[i];i=nxt[i])
		if(v^f)Solve(v,u),sum[u]+=dp[v];
	dp[u]=sum[u];
	// int now=Sum(L[fa[u][0]])+Sum(L[u]);//据我所知这个应该为0
	for(int i=Head[u];i;i=NT[i])
	{
		int fu=Sum(L[V[i]]),fv=Sum(L[U[i]]);
		dp[u]=max(dp[u],sum[u]+fu+fv+W[i]);
	}
	_Add(L[u],sum[u]-dp[u]);
	_Add(R[u]+1,dp[u]-sum[u]);//差分
}
int main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	tot=0;dfs(1,0);_dfs(1,1);tot=0;
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&u,&v,&w),
		ADD(LCA(u,v),u,v,w);
	Solve(1,0);printf("%d\n",dp[1]);
}