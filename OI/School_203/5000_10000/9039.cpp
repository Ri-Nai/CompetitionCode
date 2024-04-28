#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=2e4+5;
#define EOR(i,L,u) for(int i=L.head[u],v;v=L.to[i];i=L.nxt[i])
int n,m,T,Cas,W[N],val[N],stk[N],sz[N],top,low[N],blg[N],blk,dfn[N],num,vis[N];
bitset<10005>dp[N],res,R;
int rd()
{
	int t=0,c;do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
struct Link
{
	int to[M],nxt[M],head[N],tot;
	Link(){memset(head,0,sizeof head);tot=0;}
	void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
}A,B;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void Tarjan(int u)
{
	dfn[u]=low[u]=++num;
	stk[++top]=u;vis[u]=Cas;
	EOR(i,A,u)
		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]==Cas)low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		int v;val[++blk]=W[u];sz[blk]=0;
		dp[blk].reset();dp[blk].set(0);
		do
			++sz[blg[v=stk[top--]]=blk],
			val[blk]=gcd(val[blk],W[v]),
		vis[v]=0;while(v!=u);
	}
}
namespace Solution
{
	int in[N];
	void work(int u)
	{
		if(sz[u]==1)dp[u]|=(dp[u]>>val[u]|dp[u]<<val[u])&R;
		else for(int now=val[u],tot=T/val[u]+1,p=1;tot>0;tot-=p,p<<=1,now<<=1)
			dp[u]|=(dp[u]>>now|dp[u]<<now)&R;
	}
	void dfs(int u)
	{
		vis[u]=Cas;
		EOR(i,B,u)
		{
			if(vis[v]^Cas)dfs(v);
			dp[u]|=dp[v];
		}
		work(u);
	}
	void solve_dfs()
	{
		for(int i=1;i<=blk;++i)if(vis[i]^Cas)dfs(i),res|=dp[i];
	}
	void solve_topo()
	{
		memset(in,0,sizeof in);top=0;
		for(int u=1;u<=blk;++u)EOR(i,B,u)++in[v];
		for(int i=1;i<=blk;++i)if(!in[i])stk[++top]=i;
		while(top)
		{
			int u=stk[top--];
			work(u);res|=dp[u];
			EOR(i,B,u)
			{
				dp[v]|=dp[u];
				if(!--in[v])stk[++top]=v;
			}
		}
	}
}
void solve()
{
	n=rd();m=rd();T=rd();blk=num=0;
	A=Link();B=Link();res.reset();
	memset(low,0,sizeof low);
	memset(dfn,0,sizeof dfn);
	R.reset();
	for(int i=0;i<=T;++i)R.set(i);
	for(int i=1;i<=n;++i)W[i]=rd();
	for(int i=1,u;i<=m;++i)u=rd(),A.Add(u,rd());
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int u=1;u<=n;++u)EOR(i,A,u)
		if(blg[u]^blg[v])B.Add(blg[u],blg[v]);
	Solution::solve_dfs();
	for(int i=T;~i;--i)if(res.test(i))return (void)printf("%d\n",i);
}
int main()
{
	Cas=rd();T=rd();++Cas;
	while(--Cas)solve();
}