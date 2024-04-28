#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int fa[20][maxn],dep[maxn],n,m,A[maxn];
int nxt[maxn<<1],to[maxn<<1],head[maxn],num;
int Trie[maxn*20][2],sum[maxn*20],RT[maxn],tot;
inline void Add(const int &u,const int &v)
{
	to[++num]=v;nxt[num]=head[u];head[u]=num;
}
void updata(int &rt,int ot,int val)
{
	int now=++tot;rt=tot;
	sum[now]=sum[ot]+1;
	for(int i=16;~i;--i)
	{
		int p=(val>>i)&1;
		Trie[now][0]=Trie[ot][0];
		Trie[now][1]=Trie[ot][1];
		now=Trie[now][p]=++tot;
		ot=Trie[ot][p];
		sum[now]=sum[ot]+1;
	}
}
void dfs(int now,int from)
{
	fa[0][now]=from;
	dep[now]=dep[from]+1;
	updata(RT[now],RT[from],A[now]);
	for(int i=1;i<=16;++i)fa[i][now]=fa[i-1][fa[i-1][now]];
	for(int i=head[now];~i;i=nxt[i])if(to[i]!=from)dfs(to[i],now);
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	int step=dep[u]-dep[v];
	for(int i=0;i<=16;++i)
		if(1<<i&step)u=fa[i][u];
	if(u==v)return v;
	for(int i=16;~i;--i)
		if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int query(int ru,int rv,int rl,int val)
{
	int res=0;
	for(int i=16;~i;--i)
	{
		int p=(val>>i)&1;
		if(sum[Trie[ru][p^1]]+sum[Trie[rv][p^1]]-2*sum[Trie[rl][p^1]]>0)
			res|=1<<i,ru=Trie[ru][p^1],rv=Trie[rv][p^1],rl=Trie[rl][p^1];
		else ru=Trie[ru][p],rv=Trie[rv][p],rl=Trie[rl][p];
	}
	return res;
}
void CLEAR()
{
	tot=num=0;
	memset(fa,0,sizeof fa);
	memset(sum,0,sizeof sum);
	memset(Trie,0,sizeof Trie);
	memset(head,-1,sizeof head);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		CLEAR();
		for(int i=1;i<=n;++i)scanf("%d",&A[i]);
		for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
		dfs(1,0);
		for(int i=1,u,v,w;i<=m;++i)
		{
			scanf("%d%d%d",&u,&v,&w);
			int lca=LCA(u,v);
			printf("%d\n",max(query(RT[u],RT[v],RT[lca],w),w^A[lca]));
		}

	}
}