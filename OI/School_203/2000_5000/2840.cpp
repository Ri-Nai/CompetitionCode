#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
LL C[N];
int n,m,L[N],R[N],num,fa[20][N],dep[N];
int nxt[N<<1],head[N],to[N<<1],tot;
inline void Adde(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v,head[u]=tot;
}
void dfs(int u,int f)
{
	L[u]=++num;fa[0][u]=f;dep[u]=dep[f]+1;
	for(int i=1;i<=18;++i)
		fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)dfs(to[i],u);
	R[u]=num;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	int step=dep[u]-dep[v];
	for(int i=0;i<=18;++i)
		if(1<<i&step)u=fa[i][u];
	if(u==v)return v;
	for(int i=18;~i;--i)
		if(fa[i][u]^fa[i][v])
			u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
LL Sum(int x)
{
	LL res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		Adde(u,v),Adde(v,u);
	dfs(1,0);
	for(int u,op,v,w;m--;)
	{
		scanf("%d%d",&op,&u);
		if(op==2)printf("%lld\n",Sum(R[u])-Sum(L[u]-1));
		else 
		{
			scanf("%d%d",&v,&w);
			int l=LCA(u,v),f=fa[0][l];
			Add(L[u],w);Add(L[v],w);
			if(l)Add(L[l],-w);if(f)Add(L[f],-w);
		}
	}
}