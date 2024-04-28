#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e4+5,M=2e5+5;
bool mark[N],vis[N],is[N];
int n,m,s,t,Q[N],stp[N],L,R;
int nxt[M],to[M],head[N],tot;
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u)
{
	mark[u]=1;
	for(int i=head[u],v;v=to[i];i=nxt[i])
	{
		if(u==v)continue;
		if(!mark[v])dfs(v);
	}
}
int bfs()
{
	Q[++R]=t;stp[t]=0;vis[t]=1;
	while(L<R)
	{
		int u=Q[++L];
		if(u==s)return stp[u];
		for(int i=head[u],v;v=to[i];i=nxt[i])
			if(!vis[v]&&is[v])stp[Q[++R]=v]=stp[u]+1,vis[v]=1;
	}
	return -1;
}
int main()
{
	// FILE("road");
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),Add(v,u);
	scanf("%d%d",&s,&t);
	dfs(t);
	for(int i=1;i<=n;++i)is[i]=mark[i];
	for(int i=1;i<=n;++i)
		for(int j=head[i];j;j=nxt[j])
			is[to[j]]&=mark[i];
	printf("%d\n",bfs());FCLS();
}