#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,P=305;
int n,m,K,E,A[N],B[N],f[P][P];
double p[N],dp[N][2];
int TMin(int &x,int y){y<x&&(x=y);}
int main()
{
	cin>>n>>m>>K>>E; 
	memset(f,0x3f,sizeof f);
	const double inf=1.*f[0][0]*f[0][0];
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)scanf("%d",&B[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&p[i]);
	for(int i=1;i<=K;++i)f[i][i]=0;
	for(int u,v,w;E--;)
	{
		scanf("%d%d%d",&u,&v,&w);
		TMin(f[u][v],w);
		TMin(f[v][u],w);
	}
	for(int k=1;k<=K;++k)
		for(int i=1;i<=K;++i)
			for(int j=1;j<=K;++j)
				TMin(f[i][j],f[i][k]+f[k][j]);
	for(int j=0;j<=m;++j)dp[j][0]=dp[j][1]=inf;
	dp[0][0]=dp[1][1]=0;//一开始无体力
	for(int i=2;i<=n;++i)
	{
		cur^=1;
		int ed=min(i,m);
		double S=p[i-1],F=1-S,SS=p[i],FF=1-SS;
		for(int j=ed;j;--j)
		{
			dp[j][0]=min(dp[j][0]+f[A[i-1]][A[i]],dp[j][1]+S*f[B[i-1]][A[i]]+F*f[A[i-1]][A[i]]);
			dp[j][1]=min(dp[j-1][1]+S*SS*f[B[i-1]][B[i]]+S*FF*f[B[i-1]][A[i]]+F*SS*f[A[i-1]][B[i]]+F*FF*f[A[i-1]][A[i]],dp[j-1][0]+SS*f[A[i-1]][B[i]]+FF*f[A[i-1]][A[i]]);
		}
		dp[0][0]=dp[0][0]+f[A[i]][A[i-1]];//死不申请
	}
	double ans=inf;
	for(int i=0;i<=m;++i)ToMin(ans,min(dp[i][0],dp[i][1]));
	printf("%.2f\n",ans);
}
/*
3 2 3 3
2 1 2
1 2 1
0.8 0.2 0.5
1 2 5
1 3 3
2 3 1

这个是否申请,已经用过几次申请机会 

考虑到这次的体力值之与上次的教室位置有关
好处是1可以滚动,2可以存是否申请过
 
分四种情况讨论是否申请成功就是了 

*/
