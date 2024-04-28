#include<bits/stdc++.h>
#define mid (L+R>>1)
using namespace std;
const int maxn=1e5+5,maxm=1.5e7+5;
int n,m,A[maxn],B[maxn],fa[20][maxn],from[maxn],dep[maxn],son[maxn],len,T;
int tot,sum[maxm],ls[maxm],rs[maxm],RT[maxn];
int cnt,to[maxn<<1],head[maxn],nxt[maxn<<1];
void Add(int u,int v)
{
	to[++cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
}
void build(int L,int R,int &rt)
{
	rt=++tot;if(L==R)return ;
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
}
void updata(int L,int R,int x,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot]+1;
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==R)return;
	if(x<=mid)updata(L,mid,x,ls[ot],ls[rt]);
	else updata(mid+1,R,x,rs[ot],rs[rt]);
}
int query(int L,int R,int x,int ru,int rv,int rl,int rf)
{
	if(L==R)return L;
	int now=sum[ls[ru]]+sum[ls[rv]]-sum[ls[rl]]-sum[ls[rf]];
	if(x<=now)return query(L,mid,x,ls[ru],ls[rv],ls[rl],ls[rf]);
	else return query(mid+1,R,x-now,rs[ru],rs[rv],rs[rl],rs[rf]);
}
void Up(int &x,int step)
{
	for(int i=0;i<=19;++i)
		if(1<<i&step)x=fa[i][x];
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	Up(u,dep[u]-dep[v]);
	if(u==v)return v;
	for(int i=19;~i;--i)
		if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
void dfs(int now,int f,int rt)
{
	dep[now]=dep[f]+1;fa[0][now]=f;
	from[now]=rt;++son[rt];
	updata(1,len,A[now],RT[f],RT[now]);
	for(int i=1;i<=19;++i)
		fa[i][now]=fa[i-1][fa[i-1][now]];
	for(int i=head[now];i;i=nxt[i])
		if(to[i]!=f)dfs(to[i],now,rt);
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i],from[i]=i;
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),
		Add(u,v),Add(v,u);
	build(1,len,RT[0]);
	for(int i=1;i<=n;++i)
		if(i==from[i])dfs(i,0,i);
	int ans=0;
	while(T--)
	{
		int u,v,k;char tmp[2];
		scanf("%s%d%d",tmp,&u,&v);
		u^=ans;v^=ans;
		if(tmp[0]=='Q')
		{
			scanf("%d",&k);k^=ans;
			int lca=LCA(u,v);
			printf("%d\n",ans=B[query(1,len,k,RT[u],RT[v],RT[lca],RT[fa[0][lca]])]);
		}
		else
		{
			int fu=from[u],fv=from[v];
			Add(u,v);Add(v,u);
			if(son[fu]>son[fv])dfs(v,u,fu);
			else dfs(u,v,fv);
		}

	}
}