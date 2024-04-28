#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int nxt[N<<1],head[N],to[N<<1],tot;
int n,m,A[N],son[N],sz[N],fa[N],L[N],R[N],Re[N],num,mx,cnt[N];
long long sum,ans[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v,head[u]=tot;
}
void dfs(int u,int f)
{
	fa[u]=f;son[u]=0;sz[u]=1;Re[L[u]=++num]=u;
	for(int i=head[u],v;v=to[i],i;i=nxt[i])
	{
		if(v==f)continue;dfs(v,u);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}R[u]=num;
}
inline void Addk(int u,int v)
{
	for(int i=L[u];i<=R[u];++i)
	{
		int &now=Re[i];
		cnt[A[now]]+=v;
		if(v>0)
		{
			if(cnt[A[now]]>mx)mx=cnt[sum=A[now]];
			else if(cnt[A[now]]==mx)sum+=A[now];
		}
	}
	if(v<0)sum=mx=0;
}
void _dfs(int u)
{
	for(int i=head[u],v;v=to[i],i;i=nxt[i])
		if(v!=fa[u]&&v!=son[u])_dfs(v),Addk(v,-1);
	if(son[u])_dfs(son[u]);
	for(int i=head[u],v;v=to[i],i;i=nxt[i])
		if(v!=fa[u]&&v!=son[u])Addk(v,1);
	++cnt[A[u]];
	if(cnt[A[u]]>mx)mx=cnt[sum=A[u]];
	else if(cnt[A[u]]==mx)sum+=A[u];
	ans[u]=sum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	dfs(1,0);_dfs(1);for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
}