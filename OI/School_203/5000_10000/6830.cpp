#include<cstdio>
#define F(i,t,n) for(int i=t;i<=n;++i)
double dp[105][105],ans=0;
int main()
{
	int q,n;
	scanf("%d%d",&q,&n);
	if(q==1)F(i,2,n)ans+=2.0/i;
	else
	{
		dp[1][0]=1;
		F(i,2,n)F(ls,1,i-1)
		{
			int rs=i-ls;
			F(ld,0,ls-1)F(rd,0,rs-1)
			{
				const int &dep=(ld>rd?ld+1:rd+1);
				dp[i][dep]+=dp[ls][ld]*dp[rs][rd]/(i-1);
			}
		}
		F(i,1,n)ans+=dp[n][i]*i;
	}
	printf("%.6f\n",ans);
}