#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
#define LL long long
const int N=1e5+5;
int head[N],nxt[N<<1],to[N<<1],tot;
int n,m,RT,fa[N],top[N],sz[N],son[N],dep[N],L[N],R[N],Re[N],num;
LL A[N],mn[N<<2],lazy[N<<2];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
void dfs(int u,int f)
{
	sz[u]=1;son[u]=0;fa[u]=f;dep[u]=dep[f]+1;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;L[u]=++num;Re[num]=u;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];
		if(v==fa[u]||v==son[u])
		continue;_dfs(v,v);
	}
	R[u]=num;
}
inline void Up(int p){mn[p]=min(mn[ls],mn[rs]);}
inline void change(int p,LL t){lazy[p]=mn[p]=t;}
inline void Down(int p){LL &t=lazy[p];if(!t)return;change(ls,t);change(rs,t);}
void build(int L=1,int R=n,int p=1)
{
	if(L==R){mn[p]=A[Re[L]];return;}
	int mid=L+R>>1;
	build(L,mid,ls);build(mid+1,R,rs);
	Up(p);
}
void updata(int l,int r,LL x,int L=1,int R=n,int p=1)
{
	if(L==l&&r==R){change(p,x);return ;}
	int mid=L+R>>1;Down(p);
	if(r<=mid)updata(l,r,x,L,mid,ls);
	else if(l>mid)updata(l,r,x,mid+1,R,rs);
	else updata(l,mid,x,L,mid,ls),updata(mid+1,r,x,mid+1,R,rs);
	Up(p);
}
LL query(int l,int r,int L=1,int R=n,int p=1)
{
	if(L==l&&r==R)return mn[p];
	int mid=L+R>>1;Down(p);
	if(r<=mid)return query(l,r,L,mid,ls);
	else if(l>mid)return query(l,r,mid+1,R,rs);
	else return min(query(l,mid,L,mid,ls),query(mid+1,r,mid+1,R,rs));
}
void solve(int u,int v,LL w)
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		updata(L[top[u]],L[u],w);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	updata(L[u],L[v],w);
}
LL Get(int u)
{
	if(u==RT)return query(1,n);
	if(L[RT]<=L[u]||R[u]<L[RT])return query(L[u],R[u]);
	int v=RT;while(top[fa[v]]^top[u])v=top[fa[v]];
	if(fa[v]!=u)v=son[u];
	LL res=1e10;
	if(L[v]-1>=1)res=query(1,L[v]-1);
	if(R[v]+1<=n)res=min(res,query(R[v]+1,n));
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for(int i=1;i<=n;++i)scanf("%lld",&A[i]);
	scanf("%d",&RT);dfs(RT,0);_dfs(RT,RT);build();
	while(m--)
	{
		int u,v,op;LL w;
		scanf("%d",&op);
		if(op==1)scanf("%d",&RT);
		if(op==2)scanf("%d%d%lld",&u,&v,&w),solve(u,v,w);
		if(op==3)scanf("%d",&u),printf("%lld\n",Get(u));
	}
}