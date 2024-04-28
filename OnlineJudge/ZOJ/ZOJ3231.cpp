#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int head[maxn],nxt[maxn<<1],to[maxn<<1],W[maxn<<1],tot;
int n,A[maxn],sum,Avg,Rst,B[maxn],C[maxn],dp[maxn][maxn];
void _fs(int u,int f)
{
	B[u]=A[u];C[u]=1;
	for(int i=head[u];~i;i=nxt[i])
	{
		int v=to[i];if(v==f)continue;
		_fs(v,u);B[u]+=B[v];C[u]+=C[v];
	}
}
void dfs(int u,int f)
{
	dp[u][0]=dp[u][1]=0;
	for(int i=head[u];~i;i=nxt[i])
	{
		int v=to[i];if(v==f)continue;
		dfs(v,u);
		for(int j=Rst;~j;--j)
		{
			int tmp=0x3f3f3f3f;
			for(int k=min(j,min(C[v],Rst));~k;--k)
				tmp=min(tmp,dp[u][j-k]+dp[v][k]+W[i]*abs(k-B[v]));
			dp[u][j]=tmp;
		}
	}
}
void Add(int u,int v,int w)
{
    nxt[++tot]=head[u];
    to[tot]=v;W[tot]=w;
    head[u]=tot;
}
void solve()
{
	memset(head,-1,sizeof head);
	memset(dp,0x3f,sizeof  dp );
	tot=sum=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),sum+=A[i];
	Avg=sum/n;Rst=sum%n;
	for(int i=1;i<=n;++i)A[i]-=Avg;
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),
		Add(++u,++v,w),Add(v,u,w);
	_fs(1,0);dfs(1,0);printf("%d\n",dp[1][Rst]);
}
int main()
{
	while(~scanf("%d",&n))solve();
}