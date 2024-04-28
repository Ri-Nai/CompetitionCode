#include<cstdio>
const int maxn=205;
int A[maxn],O[maxn],n;
double P[maxn],dp[2][maxn];
void solve()
{
	int cas=0;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=n;++i)scanf("%d",&A[i]);
		for(int i=1;i<=n;++i)
		{
			char c[3];
			scanf("%s",c);
			if(c[0]=='^')O[i]=1;
			if(c[0]=='|')O[i]=2;
			if(c[0]=='&')O[i]=3;
		}
		for(int i=1;i<=n;++i)scanf("%lf",&P[i]);
		double ans=0;
		for(int i=0;i<20;++i)
		{
			dp[1][0]=(double)((A[0]>>i)&1);
			dp[0][0]=1.0-dp[1][0];
			for(int j=1;j<=n;++j)
			{
				dp[1][j]=dp[1][j-1]*P[j];
				dp[0][j]=dp[0][j-1]*P[j];
				const double &q=1-P[j];
				if(1<<i&A[j])
				{
					if(O[j]==1)
						dp[1][j]+=dp[0][j-1]*q,
						dp[0][j]+=dp[1][j-1]*q;
					if(O[j]==2)
						dp[1][j]+=(dp[0][j-1]+dp[1][j-1])*q;
					if(O[j]==3)
						dp[1][j]+=dp[1][j-1]*q,
						dp[0][j]+=dp[0][j-1]*q;
				}
				else
				{
					if(O[j]==1||O[j]==2)
						dp[1][j]+=dp[1][j-1]*q,
						dp[0][j]+=dp[0][j-1]*q;
					if(O[j]==3)
						dp[0][j]+=(dp[1][j-1]+dp[0][j-1])*q;
				}
			}
			ans+=1.0*(1<<i)*dp[1][n];
		}
		printf("Case %d:\n%.6f\n",++cas,ans);
	}
}
int main()
{
	solve();
}