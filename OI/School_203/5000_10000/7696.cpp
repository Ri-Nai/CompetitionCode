#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=515;//500上限512
int n,fa[N],head[N],to[N],nxt[N],mx,tot,ans[M],f[N][M],len[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u)
{
	f[u][0]=1;//总数
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];dfs(v);
		for(int j=0;j<=len[u];++j)
			for(int k=0;k<=len[v];++k)
			{
				ans[j^k+1]+=f[u][j]*f[v][k];
				mx=max(mx,j^k+1);
			}
		len[u]=max(len[u],len[v]+1);
		for(int j=1;j<=len[u];++j)
			f[u][j]+=f[v][j-1];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
		scanf("%d",&fa[i]),Add(fa[i],i);
	dfs(1);
	for(int i=0;i<=mx;++i)
		printf("%d\n",ans[i]);
}
