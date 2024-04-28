#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ago;
int n,fa[N],A[N],in[N],stk[N],top;
ago dp[2][N],f[2][2][N],ans;
int rd()
{
	int t=0,c;do c=getchar();while(!isdigit(c));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
void Climb(int u)
{
	f[0][1][u]=dp[1][u];
	f[1][0][u]=dp[0][u];in[u]=0;
	for(int v=fa[u];in[v];in[v]=0,u=v,v=fa[v])
	{
		f[0][0][v]=max(f[0][1][u],f[0][0][u])+dp[0][v];
		f[1][0][v]=max(f[1][1][u],f[1][0][u])+dp[0][v];

		f[0][1][v]=f[0][0][u]+dp[1][v];
		f[1][1][v]=f[1][0][u]+dp[1][v];
	}
	ans+=max(f[1][0][u],max(f[1][1][u],f[0][0][u]));
}
int main()
{
	n=rd();
	for(int i=1;i<=n;++i)
		dp[1][i]=A[i]=rd(),++in[fa[i]=rd()];
	for(int i=1;i<=n;++i)!in[i]&&(stk[++top]=i);
	while(top)
	{
		int u=stk[top--],v=fa[u];
		dp[0][v]+=max(dp[0][u],dp[1][u]);
		dp[1][v]+=dp[0][u];
		!--in[v]&&(stk[++top]=v);
	}
	for(int i=1;i<=n;++i)if(in[i])Climb(i);
	printf("%lld\n",ans);
}