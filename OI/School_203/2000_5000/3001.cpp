#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,ans,f[N],g[N],nxt[N<<1],to[N<<1],head[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u,int fa)
{
	g[u]=f[u]=1;
	for(int i=head[u],v;(v=to[i]);i=nxt[i])
	{
		if(v==fa)continue;dfs(v,u);
		f[u]=(1ll*f[u]*(g[v]+1)+1ll*f[v]*g[u])%mod;
		g[u]=1ll*g[u]*(g[v]+1)%mod;
	}
	ans=(ans+f[u])%mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(++u,++v),Add(v,u);
	dfs(1,1);printf("%d\n",ans);
}