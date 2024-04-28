#include<bits/stdc++.h>
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
using namespace std;
const int N=5e4+5;
int n,m,A[N],top[N],fa[N],son[N],sz[N],id[N],dep[N],Re[N],num;
int nxt[N<<1],head[N],to[N<<1],tot,lazy[N<<2];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
struct node
{
	int lmx,rmx,mn,mx;
	node(){lmx=rmx=mx=0;mn=1e9;}
	node(int _1,int _2,int _3,int _4){lmx=_1,rmx=_2,mn=_3,mx=_4;}
}Tree[N<<2];
void dfs(int u,int f)
{
	sz[u]=1;son[u]=0;dep[u]=dep[fa[u]=f]+1;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;id[u]=++num;Re[num]=u;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=son[u]&&to[i]!=fa[u])_dfs(to[i],to[i]);
}
void change(int p,int t)
{
	Tree[p].mx+=t;Tree[p].mn+=t;lazy[p]+=t;
}
void Down(int p)
{
	int &t=lazy[p];if(!t)return;
	change(p<<1,t),change(p<<1|1,t);t=0;
}
node Up(node L,node R)
{
	node res;
	res.mn=min(L.mn,R.mn);
	res.mx=max(L.mx,R.mx);
	res.lmx=max(max(L.lmx,R.lmx),L.mx-R.mn);
	res.rmx=max(max(R.rmx,L.rmx),R.mx-L.mn);
	return res;
}
void build(int L=1,int R=n,int p=1)
{
	if(L==R){Tree[p]=node(0,0,A[Re[L]],A[Re[L]]);return;}
	int mid=L+R>>1;build(Lson);build(Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1]);
}
void updata(int l,int r,int x,int L=1,int R=n,int p=1)
{
	if(L==l&&r==R){change(p,x);return;}
	Down(p);int mid=L+R>>1;
	if(r<=mid)updata(l,r,x,Lson);
	else if(l>mid)updata(l,r,x,Rson);
	else updata(l,mid,x,Lson),updata(mid+1,r,x,Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1]);
}
node query(int l,int r,int L=1,int R=n,int p=1)
{
	if(L==l&&r==R)return Tree[p];
	Down(p);int mid=L+R>>1;
	if(r<=mid)return query(l,r,Lson);
	else if(l>mid)return query(l,r,Rson);
	return Up(query(l,mid,Lson),query(mid+1,r,Rson));
}
int solve(int u,int v,int w)
{
	node L,R;
	while(top[u]^top[v])
		if(dep[top[u]]>dep[top[v]])
			L=Up(query(id[top[u]],id[u]),L),
			updata(id[top[u]],id[u],w),u=fa[top[u]];
		else
			R=Up(query(id[top[v]],id[v]),R),
			updata(id[top[v]],id[v],w),v=fa[top[v]];
	if(id[u]>id[v])L=Up(query(id[v],id[u]),L),updata(id[v],id[u],w);
	else R=Up(query(id[u],id[v]),R),updata(id[u],id[v],w);
	return max(R.mx-L.mn,max(L.lmx,R.rmx));
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=2,u,v;i<=n;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for(dfs(1,0),_dfs(1,1),build(),scanf("%d",&m);m--;)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);printf("%d\n",solve(u,v,w));
	}
}