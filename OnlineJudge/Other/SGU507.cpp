#include<bits/stdc++.h>
using namespace std;
typedef set<int>::iterator st;
#define Abs(x) ((x)<0?(-(x)):x)
const int inf=(1<<30)-1+(1<<30),N=5e4+5;
set<int>S[N];
int ans[N],n,m;
int nxt[N],to[N],head[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
void Merge(int u,int v)
{
	ans[u]=min(ans[u],ans[v]);
	if(S[u].size()<S[v].size())swap(S[u],S[v]);
	for(st it=S[v].begin();it!=S[v].end();++it)
	{
		st now=S[u].lower_bound(*it),pre=now;
		if(now!=S[u].begin())--pre;
		if(now!=S[u].end())ans[u]=min(ans[u],Abs(*now-*it));
		if(pre!=S[u].end())ans[u]=min(ans[u],Abs(*it-*pre));
		S[u].insert(*it);
	}
}
void _dfs(int u)
{
	if(!head[u])S[u].insert(ans[u]);
	ans[u]=inf;
	for(int i=head[u];i;i=nxt[i])
		_dfs(to[i]),Merge(u,to[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2,u;i<=n;++i)scanf("%d",&u),Add(u,i);
	for(int i=n-m+1;i<=n;++i)scanf("%d",&ans[i]);_dfs(1);
	printf("%d",ans[1]);for(int i=2;i<=n-m;++i)printf(" %d",ans[i]);
	puts("");
}