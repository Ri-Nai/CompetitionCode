#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=1e5+5;
int n,m,k,nxt[M],to[M],head[N],in[N],tot,vis[N];
bitset<N>P[N],ans,res;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;in[v]=1;
}
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=1;P[u].set(u);
	for(int i=head[u];i;i=nxt[i])
		dfs(to[i]),P[u]|=P[to[i]];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int u,v;m--;)
		scanf("%d%d",&u,&v),Add(u,v);
	for(int i=1;i<=n;++i)dfs(i);
	for(int u;k--;)
	{
		scanf("%d",&u);
		res.set();
		for(int j=1;j<=n;++j)
			if(!in[j]&&P[j][u])res&=P[j];
		ans|=res;
	}
	for(int i=1;i<=n;++i)
		if(ans[i])printf("%d ",i);
}