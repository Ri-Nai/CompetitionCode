#include<bits/stdc++.h>
using namespace std;
const int K=20,N=5e4+5,M=N<<1;
struct Node
{
	int mx,mn,ans;
	Node(){ans=mx=0,mn=1e9;}
	Node(int _){mx=mn=_;ans=0;}
	void Up(Node A,Node B)
	{
		mx=max(A.mx,B.mx);mn=min(A.mn,B.mn);
		ans=max(B.mx-A.mn,max(A.ans,B.ans));
	}
}Fwd[N][K],Rvs[N][K];
int n,Q,W[N],fa[N][K],dep[N];
int nxt[M],to[M],head[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
int LCA(int u,int v)
{
	int mn=1e9,mx=0;
	if(dep[u]<dep[v])swap(u,v);
	int step=dep[u]-dep[v];
	for(int i=0;i<K;++i)
		if(1<<i&step)u=fa[u][i];
	if(u==v)return u;
	for(int i=K-1;~i;--i)
		if(fa[u][i]^fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs(int u,int f)
{
	fa[u][0]=f;dep[u]=dep[f]+1;
	Fwd[u][0]=Node(W[f]);
	Rvs[u][0]=Node(W[u]);
	for(int i=1;i<K;++i)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		Fwd[u][i].Up(Fwd[u][i-1],Fwd[fa[u][i-1]][i-1]);
		Rvs[u][i].Up(Rvs[fa[u][i-1]][i-1],Rvs[u][i-1]);
	}
	for(int i=head[u],v;v=to[i];i=nxt[i])if(v^f)dfs(v,u);
}
int Query(int u,int v)
{
	int f=LCA(u,v),stp1=dep[u]-dep[f],stp2=dep[v]-dep[f];
	Node F=Node(W[u]),R;
	for(int i=0;i<K;++i)
	{
		if(1<<i&stp1)F.Up(F,Fwd[u][i]),u=fa[u][i];
		if(1<<i&stp2)R.Up(Rvs[v][i],R),v=fa[v][i];
	}
	F.Up(F,R);return F.ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&W[i]);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		Add(u,v),Add(v,u);
	scanf("%d",&Q);dfs(1,0);
	for(int i=1,u,v;i<=Q;++i)
		scanf("%d%d",&u,&v),
		printf("%d\n",Query(u,v));
}