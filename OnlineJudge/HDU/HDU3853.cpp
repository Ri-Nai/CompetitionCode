#include<cstdio>
const int maxn=1005;
double dp[maxn][maxn],D[maxn][maxn],
		R[maxn][maxn],M[maxn][maxn];
int n,m;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%lf%lf%lf",&M[i][j],&R[i][j],&D[i][j]);
		for(int i=n;i>0;--i)
            for(int j=m;j>0;--j)
            {
            	dp[i][j]=0;
                if(i==n&&j==m)continue;
                if(1-M[i][j]==0)continue;
                dp[i][j]=(1+dp[i][j+1]*R[i][j]+dp[i+1][j]*D[i][j])/(1-M[i][j]);
            }
        printf("%.3lf\n",2*dp[1][1]);
	}
}