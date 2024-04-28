#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=1e5+5;
int n,m,fa[maxn],top[maxn],dep[maxn],lazy[maxn<<2],
id[maxn],sz[maxn],son[maxn],num,Re[maxn],A[maxn];
int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
struct node
{
	int sum,Rc,Lc;
	node(){sum=0;Rc=Lc=-1;}
	node(int _,int __,int ___){sum=_;Rc=__;Lc=___;}
}Tree[maxn<<2];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
void dfs(int u,int f)
{
	son[u]=0;sz[u]=1;dep[u]=dep[f]+1;fa[u]=f;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	id[u]=++num;top[u]=tp;Re[num]=u;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];
		if(v==fa[u]||v==son[u])continue;
		_dfs(v,v);
	}
}
inline node Up(node L,node R)
{
	node n;
	n.sum=L.sum+R.sum;
	n.Rc=R.Rc;n.Lc=L.Lc;
	if(L.Rc==R.Lc)--n.sum;
	return n;
}
inline void change(int p,int t)
{
	Tree[p]=node(1,t,t);lazy[p]=t;
}
inline void Down(int p)
{
	if(!lazy[p])return ;
	change(ls,lazy[p]);
	change(rs,lazy[p]);
	lazy[p]=0;
}
void build(int L=1,int R=n,int p=1)
{
	if(L==R)
	{
		Tree[p]=node(1,A[Re[L]],A[Re[L]]);
		return ;
	}
	int mid=L+R>>1;
	build(L,mid,ls);build(mid+1,R,rs);
	Tree[p]=Up(Tree[ls],Tree[rs]);
}
void updata(int l,int r,int x,int L=1,int R=n,int p=1)
{
	if(L==l&&R==r){change(p,x);return ;}
	Down(p);int mid=L+R>>1;
	if(r<=mid)updata(l,r,x,L,mid,ls);
	else if(l>mid)updata(l,r,x,mid+1,R,rs);
	else updata(l,mid,x,L,mid,ls),updata(mid+1,r,x,mid+1,R,rs);
	Tree[p]=Up(Tree[ls],Tree[rs]);
}
node query(int l,int r,int L=1,int R=n,int p=1)
{
	if(L==l&&R==r){return Tree[p];}
	Down(p);int mid=L+R>>1;
	if(r<=mid)return query(l,r,L,mid,ls);
	else if(l>mid)return query(l,r,mid+1,R,rs);
	else return Up(query(l,mid,L,mid,ls),query(mid+1,r,mid+1,R,rs));
}
inline void Get(int L,int R,node &n)
{
	node tmp=query(L,R);
	if(!n.sum)n=tmp;
	else n=Up(tmp,n);
}
int Solve(int u,int v,int w)
{
	node L,R,tmp;
	while(top[u]^top[v])
	{
		if(dep[top[u]]>dep[top[v]])
		{
			if(~w)updata(id[top[u]],id[u],w);
			else 
				tmp=query(id[top[u]],id[u]),
				swap(tmp.Lc,tmp.Rc),L=Up(L,tmp);
			u=fa[top[u]];
		}
		else
		{
			if(~w)updata(id[top[v]],id[v],w);
			else 
				tmp=query(id[top[v]],id[v]),R=Up(tmp,R);
			v=fa[top[v]];
		}
	}
	if(~w)
	{
		if(id[u]>id[v])swap(u,v);
		updata(id[u],id[v],w);
		return 0;
	}
	if(id[u]<id[v])tmp=query(id[u],id[v]);
	else tmp=query(id[v],id[u]),swap(tmp.Lc,tmp.Rc);
	L=Up(L,tmp);R=Up(L,R);
	return R.sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	dfs(1,0);_dfs(1,1);build();char s[2];
	for(int u,v,w;m--;)
	{
		scanf("%s%d%d",s,&u,&v);
		if(s[0]=='C')scanf("%d",&w),Solve(u,v,w);
		else printf("%d\n",Solve(u,v,-1));
	}
}