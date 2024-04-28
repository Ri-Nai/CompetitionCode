#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5,M=1e6+5;
int nxt[M],head[N],to[M],tot;
int n,m,dfn[N],low[N],sz[N],num;LL ans[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void Tarjan(int u)
{
	int now=0;sz[u]=1;
	dfn[u]=low[u]=++num;
	for(int i=head[u],v;v=to[i];i=nxt[i])
		if(dfn[v])low[u]=min(low[u],dfn[v]);
		else
		{
			Tarjan(v);low[u]=min(low[u],low[v]);
			sz[u]+=sz[v];if(low[v]>=dfn[u])
				ans[u]+=1ll*now*sz[v],now+=sz[v];
		}
	ans[u]+=1ll*now*(n-now-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;++i)printf("%lld\n",2ll*(ans[i]+n-1));
}