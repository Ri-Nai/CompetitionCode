#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5,M=1e6+5;
int head[N],nxt[N<<1],to[N<<1],W[N<<1],tot;
int n,k,sz[N],son[N],fa[N],dep[N],L[N],R[N],Re[N],num,ans=1e9;
map<LL,int>mp;
LL dis[N];
inline void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];W[tot]=w;
	to[tot]=v;head[u]=tot;
}
void dfs(int u,int f)
{
	sz[u]=1;son[u]=0;L[u]=++num;
	fa[u]=f;dep[u]=dep[f]+1;Re[num]=u;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dis[v]=dis[u]+W[i];
		dfs(v,u);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}R[u]=num;
}
void check(int u,int v)
{
    LL Dis=dis[u]-dis[v];
    if(Dis<=k)
    {
        int res=0;
        if(mp[k-Dis+dis[v]])res=mp[k-Dis+dis[v]];
        if(res)ans=min(ans,res+dep[u]-(dep[v]<<1));
    }
}
void Add(int u)
{
    if(mp[dis[u]])mp[dis[u]]=min(mp[dis[u]],dep[u]);
    else mp[dis[u]]=dep[u];
}
void _dfs(int u)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=fa[u]&&to[i]!=son[u])_dfs(to[i]),mp.clear();
	if(son[u])_dfs(son[u]);
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];
		if(v==fa[u]||v==son[u])continue;
		for(int j=L[v];j<=R[v];++j)check(Re[j],u);
		for(int j=L[v];j<=R[v];++j)Add(Re[j]);
	}
	check(u,u);Add(u);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),
		Add(++u,++v,w),Add(v,u,w);
	dfs(1,0);_dfs(1);
	printf("%d\n",ans<=n?ans:-1);

}