#include<bits/stdc++.h>
using namespace std;
#define Rg register
const int N=3e5+5,M=N<<1;
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
int head[N],nxt[M],to[M],W[M],tot;
int n,m,dis[N],dep[N],son[N],sz[N],val[N],fa[N],top[N],mx,diff[N],now,num,id[N];
int LCA(int u,int v)//树剖应该不会被卡吧
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct Que
{
	int u,v,lca,len;
	void read()
	{
		u=rd();v=rd();
		mx=max(mx,len=dis[u]+dis[v]-(dis[lca=LCA(u,v)]<<1));
	}
	bool operator <(const Que &_)const
	{
		return len>_.len;
	}
}Q[N];
inline void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
void dfs(int u,int f)
{
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f)continue;
		dep[v]=dep[u]+1;
		dis[v]=dis[u]+(val[v]=W[i]);
		fa[v]=u;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int f,int tp)
{
	top[u]=tp;
	id[++num]=u;
	if(son[u])_dfs(son[u],u,tp);
	for(int i=head[u],v;v=to[i];i=nxt[i])
		if(v!=f&&v!=son[u])_dfs(v,u,v);
}
bool check(int T)
{
	now=num=0;
	for(int i=1;i<=n;++i)diff[i]=0;
	for(int i=1;i<=m;++i)
		if(Q[i].len>T)
		{
			++diff[Q[i].u];
			++diff[Q[i].v];
			diff[Q[i].lca]-=2;//自下向上更新
			++num;
		}
		else break;
	for(int i=n;i>=1;--i)
	{
		int u=id[i];//自下向上更新
		if(diff[u]==num&&mx-val[u]<=T)return 1;
		diff[fa[u]]+=diff[u];
	}
	return mx-now<=T;
}
int main()
{
	n=rd();m=rd();
	for(int i=1,u,v,w;i<n;++i)
		u=rd(),v=rd(),Add(u,v,w=rd()),Add(v,u,w);
	dfs(1,0);_dfs(1,0,1);
	for(int i=1;i<=m;++i)Q[i].read();
	sort(Q+1,Q+m+1);
	int l=1,r=mx-1,ans=mx;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
