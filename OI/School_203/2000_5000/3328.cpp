#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
double dp[N],ans;
int k,n,sz[N];
int head[N],to[N],nxt[N],tot;
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u)
{
	sz[u]=1;
	if(!head[u])return dp[u]=1,void();
	for(int i=head[u];i;i=nxt[i])
		dfs(to[i]),sz[u]+=sz[to[i]];
	for(int i=head[u],v;v=to[i];i=nxt[i])
		dp[u]=max(dp[u],min(dp[v],1.*sz[v]/(sz[u]-1)));//叛变的最坏情况 
	if(sz[u]>k)ans=max(ans,dp[u]);
}
int main()
{
	cin>>n>>k;
	for(int i=2,f;i<=n;++i)
		scanf("%d",&f),Add(f,i);
	dfs(1);printf("%.10f\n",ans);
}
