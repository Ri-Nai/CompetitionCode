#include<cstdio>
#include<cstring>
#include<algorithm>
double p[15][1005],dp[1050],ans;
int n,m;
void work(int bg,int ed)
{
	int len=ed-bg;
	memset(dp,0,sizeof dp);
	for(int k=0;k<n;++k)
		for(int i=(1<<len)-1;i;--i)
			for(int j=0;j<len;++j)
				if(1<<j&i)dp[i]=std::max(dp[i],dp[i^1<<j]+p[k][j+bg]);
	ans+=dp[(1<<len)-1];
}
void solve(int id)
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%lf",&p[i][j]);
	int rnd=(m-1)/n+1;ans=0;
	for(int i=0;i<rnd;++i)
	{
		int bg=i*n,ed=i*n+n;
		if(i==rnd-1)ed=m;
		work(bg,ed);
	}
	printf("Case #%d: %.5f\n",id,ans);
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}