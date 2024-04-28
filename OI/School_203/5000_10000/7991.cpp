#include<bits/stdc++.h>
using namespace std;
#define EOR(i,u) for(int i=head[u],v,w;w=W[i],v=to[i];i=nxt[i])
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
const int N=1e5+5,M=N<<1;
long long ans,dis[N];
int nxt[M],to[M],head[N],W[M],tot,vis[N],cnt;
int n,m,dep[N],fa[N],id[N],re[N],top[N],sz[N],son[N],C[N],num;
int rd()
{
    int t=0,c;do c=getchar();while(!isdigit(c));
    while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
void Add(int x,int y){while(x<=n)C[x]+=y,x+=x&-x;}
int Sum(int x,int res=0){while(x)res+=C[x],x^=x&-x;return res;}
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;W[tot]=w;
	head[u]=tot;
}
void dfs(int u,int f)
{
	sz[u]=1;
	EOR(i,u)if(v!=f)
	{
		dep[v]=dep[u]+1,dis[v]=dis[u]+w;
		dfs(v,u);sz[u]+=sz[v];fa[v]=u;
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int f,int tp)
{
	top[u]=tp;re[id[u]=++num]=u;
	if(son[u])_dfs(son[u],u,tp);
	EOR(i,u)if(v!=f&&v!=son[u])_dfs(v,u,v);
}
int LCA(int u,int v)
{
	while(top[u]^top[v])
		if(dep[top[u]]>=dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	return dep[u]<dep[v]?u:v;
}
inline long long Dis(int u,int v)
{
	return dis[u]+dis[v]-2*dis[LCA(u,v)];
}
int Query(int x)
{
	int l=1,r=n,mid,res=n;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Sum(mid)>=x)
			res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main()
{
	n=rd();m=rd();
	memset(vis,-1,sizeof vis);
	FOR(i,1,n-1)
	{
		int u=rd(),v=rd(),w=rd();
		Add(u,v,w),Add(v,u,w);
	}
	dfs(1,0);_dfs(1,0,1);
	FOR(i,1,m)
	{
		int u=rd();
		if(vis[u]==-1)Add(id[u],1),++cnt;
		int pre,nxt,now=Sum(id[u]);
		pre=re[Query(now==1?cnt:now-1)];
		nxt=re[Query(now==cnt?1:now+1)];
		if(vis[u]==1)Add(id[u],-1),--cnt;
		ans-=vis[u]*(Dis(pre,u)+Dis(nxt,u)-Dis(nxt,pre));
		vis[u]=-vis[u];
		printf("%lld\n",ans);
	}
}