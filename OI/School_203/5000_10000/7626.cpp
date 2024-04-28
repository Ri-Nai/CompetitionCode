#include<bits/stdc++.h>
using namespace std;
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
const int N=5e4+5;
int nxt[N],to[N],head[N],tot;
int fa[N],top[N],sz[N],son[N],id[N],num,n,Q;
int ans[N],sum[N<<2],lazy[N<<2];
struct Que
{
	int id,pos,flag,f;
	bool operator <(Que _)const
	{
		return pos<_.pos;
	}
}B[N<<1];
inline void Add(int u,int v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void dfs(int u)
{
	son[u]=-1;sz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];dfs(v);sz[u]+=sz[v];
		if(~son[u]&&sz[v]>sz[son[u]]||!(~son[u]))son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;id[u]=++num;
	if(~son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=son[u])_dfs(to[i],to[i]);
}
inline void change(int L,int R,int p,int t)
{
	sum[p]+=t*(R-L+1);lazy[p]+=t;
}
void Down(int L,int R,int p)
{
	int &t=lazy[p];if(!t)return;
	int mid=L+R>>1;
	change(Lson,t);change(Rson,t);
	t=0;
}
void updata(int l,int r,int L=1,int R=n,int p=1)
{
	if(l==L&&R==r){change(L,R,p,1);return;}
	Down(L,R,p);int mid=L+R>>1;
	if(r<=mid)updata(l,r,Lson);
	else if(l>mid)updata(l,r,Rson);
	else updata(l,mid,Lson),updata(mid+1,r,Rson);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
int query(int l,int r,int L=1,int R=n,int p=1)
{
	if(l==L&&R==r)return sum[p];
	Down(L,R,p);int mid=L+R>>1;
	if(r<=mid)return query(l,r,Lson);
	else if(l>mid)return query(l,r,Rson);
	else return query(l,mid,Lson)+query(mid+1,r,Rson);
}
void Add(int u)
{
	while(top[u])updata(id[top[u]],id[u]),u=fa[top[u]];
	updata(id[0],id[u]);
}
int Get(int u)
{
	int res=0;
	while(top[u])res+=query(id[top[u]],id[u]),u=fa[top[u]];
	res+=query(id[0],id[u]);
	return res;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<n;++i)
		scanf("%d",&fa[i]),Add(fa[i],i);
	for(int i=1,u,v,w;i<=Q;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		B[i]=(Que){i,u-1,-1,w};
		B[i+Q]=(Que) {i,v,1,w};
	}const int &len=Q<<1;dfs(0);_dfs(0,0);
	sort(B+1,B+len+1);int now=-1;
	for(int i=1;i<=len;++i)
	{
		while(now<B[i].pos)Add(++now);
		ans[B[i].id]+=B[i].flag*Get(B[i].f);
	}
	for(int i=1;i<=Q;++i)printf("%d\n",ans[i]%201314);
}