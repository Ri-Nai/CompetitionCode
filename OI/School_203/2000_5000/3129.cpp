#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=1e5+5;
int n,Q,L[maxn],R[maxn],dep[maxn],id[maxn],num;
int to[maxn],nxt[maxn],head[maxn],tot;
int mark[maxn<<2],lazy[maxn<<2];
void dfs(int u,int f)
{
	L[u]=++num;id[tot]=u;dep[u]=dep[f]+1;
	for(int i=head[u];i;i=nxt[i])dfs(to[i],u);
	R[u]=num;
}
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
inline void change(int p,int t)
{
	if(!mark[p])mark[p]=t;
	if(dep[mark[p]]<dep[t])mark[p]=t;
	if(dep[lazy[p]]<dep[t])lazy[p]=t;
}
inline void down(int p)
{
	if(!lazy[p])return;
	change(ls,lazy[p]);
	change(rs,lazy[p]);
	lazy[p]=0;
}
void updata(int l,int r,int x,int L=1,int R=n,int p=1)
{
	if(l==L&&R==r){change(p,x);return;}
	int mid=L+R>>1;down(p);
	if(r<=mid)updata(l,r,x,L,mid,ls);
	else if(l>mid)updata(l,r,x,mid+1,R,rs);
	else updata(l,mid,x,L,mid,ls),updata(mid+1,r,x,mid+1,R,rs);

	if(dep[mark[ls]]>dep[mark[rs]])mark[p]=mark[ls];
	else mark[p]=mark[rs];
}
int query(int x,int L=1,int R=n,int p=1)
{
	if(L==R)return mark[p];
	int mid=L+R>>1;down(p);
	if(x<=mid)return query(x,L,mid,ls);
	else return query(x,mid+1,R,rs);
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(u,v);
	dfs(1,0);updata(1,n,1);
	while(Q--)
	{
		char s[2];int x;
		scanf("%s%d",&s,&x);
		if(s[0]=='C')updata(L[x],R[x],x);
		else printf("%d\n",query(L[x]));

	}
}