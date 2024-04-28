#include<bits/stdc++.h>
const int maxn=1e5+5;
using namespace std;
int n,q,tot,num,w[maxn],RT[maxn],ans[maxn],
head[maxn],to[maxn],nxt[maxn],tre[maxn*40][2];
vector<int>E[maxn],id[maxn];
void build(int id)
{
	scanf("%d",&w[id]);
	RT[id]=++tot;
	int now=tot;
	for(int i=30;~i;--i)
	{
		if(w[id]&(1<<i))tre[now][1]=++tot;
		else tre[now][0]=++tot;
		now=tot;
	}
}
void update(int u,int v)
{
	if(tre[v][0])
		if(!tre[u][0])tre[u][0]=tre[v][0];
		else update(tre[u][0],tre[v][0]);
	if(tre[v][1])
		if(!tre[u][1])tre[u][1]=tre[v][1];
		else update(tre[u][1],tre[v][1]);
}
int query(int u,int x)
{
	int res=0,now=RT[u];
	for(int i=30;~i;--i)
	{
		int p=(x>>i)&1;
		if(tre[now][p^1])res|=(1<<i),now=tre[now][p^1];
		else if(tre[now][p])now=tre[now][p];
	}
	return res;
}
void dfs(int u)
{
	for(int i=head[u];~i;i=nxt[i])
		dfs(to[i]),update(RT[u],RT[to[i]]);
	int len=E[u].size();
	for(int i=0;i<len;++i)ans[id[u][i]]=query(u,E[u][i]);
}
inline void Add(int u,int v)
{
	to[++num]=v;
	nxt[num]=head[u];
	head[u]=num;
}
int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		tot=num=0;
		memset(tre,0,sizeof(tre));
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;++i)E[i].clear(),id[i].clear();
		for(int i=1;i<=n;++i)build(i);
		for(int i=2,f;i<=n;++i)scanf("%d",&f),Add(f,i);
		for(int i=1,u,v;i<=q;++i)
		{
			scanf("%d%d",&u,&v);
			E[u].push_back(v);
			id[u].push_back(i);
		}
		dfs(1);
		for(int i=1;i<=q;++i)
			printf("%d\n",ans[i]);
	}
}