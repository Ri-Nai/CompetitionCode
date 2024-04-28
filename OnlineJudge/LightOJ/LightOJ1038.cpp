#include<cmath>
#include<cstdio>
#include<cstring>
double dp[(int)1e5+5];
double dfs(int x)
{
	if(x==1)return 0;
	if(dp[x]!=0.0)return dp[x];
	int k=sqrt(x);
	double sum=0;int num=-1;
	for(int i=1;i<=k;++i)
	{
		if(x%i==0)
		{
			int j=x/i;
			if(i!=j)
			{
				if(j!=x)sum+=dfs(j)+1,++num;
				else sum+=1,++num;
			}
			sum+=dfs(i)+1,++num;
		}
	}
	return dp[x]=sum/num;
}
void solve(int id)
{
	int x;scanf("%d",&x);
	printf("Case %d: %.10lf\n",id,dfs(x));
}
int main()
{
	int T;scanf("%d",&T);memset(dp,0,sizeof 0);
	for(int i=1;i<=T;++i)solve(i);
}