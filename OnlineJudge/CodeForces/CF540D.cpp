#include<cstdio>
double dp[105][105][105],ansa,ansb,ansc;
int a,b,c;
double dfs(int a,int b,int c)
{
	if(dp[a][b][c]!=-1)return dp[a][b][c];
	if(b==c&&b==0&&a>0)return dp[a][b][c]=1.0;
	if(a==0)return dp[a][b][c]=0;
	double sum=a*b+b*c+c*a;
	dp[a][b][c]=0;
	if(b&&a)dp[a][b][c]+=a*b*dfs(a,b-1,c);
	if(a&&c)dp[a][b][c]+=a*c*dfs(a-1,b,c);
	if(c&&b)dp[a][b][c]+=b*c*dfs(a,b,c-1);
	return dp[a][b][c]/=1.0*sum;
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
			for(int k=0;k<=100;++k)
				dp[i][j][k]=-1;
	ansa=dfs(a,b,c);ansb=dfs(b,c,a);ansc=dfs(c,a,b);
	printf("%.12lf %.12lf %.12lf\n",ansa,ansb,ansc); 
}