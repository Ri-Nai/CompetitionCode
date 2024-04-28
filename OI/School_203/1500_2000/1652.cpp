#include<bits/stdc++.h>
using namespace std;
const int N=205,M=4e4+5;
int n,Q,A[N],B[N],L[N],R[N],head[N]
,to[M],nxt[M],tot,match[N],as;
bool vis[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
bool dfs(int u)
{
	for(int i=head[u],v;(v=to[i]);i=nxt[i])
		if(!vis[v]&&(vis[v]=1)&&(!match[v]||dfs(match[v])))
			return match[v]=u;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)L[i]=B[i]=1,R[i]=A[i]=n;
	for(int i=1,op,l,r,v;i<=Q;++i)
	{
		scanf("%d%d%d%d",&op,&l,&r,&v);
		L[v]=max(l,L[v]);R[v]=min(r,R[v]);
		if(op==1)for(int j=l;j<=r;++j)A[j]=min(v,A[j]);
		else	 for(int j=l;j<=r;++j)B[j]=max(v,B[j]);
	}
	for(int i=1;i<=n;++i)
		for(int j=B[i];j<=A[i];++j)
			if(i>=L[j]&&i<=R[j])Add(j,i);
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof vis);
		if(!dfs(i))return puts("-1"),0;
	}
	for(int i=1;i<=n;++i)printf("%d ",match[i]);
}