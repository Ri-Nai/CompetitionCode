#include<cstdio>
double dp[51][8][8][8];
double dfs(int K,int A,int B,int C)
{
	//printf("%d %d %d %d %d\n",K,BL,A,B,C);
	if(K==0)return 0;
	double &tmp=dp[K][A][B][C];
	if(tmp>0)return tmp;
	int sum=A+B+C+1;
	double res=0;
	if(A+B+C<7)
	{
		if(A>0)res+=1.0*A*dfs(K-1,A-1,B,C)/sum;
		if(B>0)res+=1.0*B*dfs(K-1,A+1,B-1,C+1)/sum;
		if(C>0)res+=1.0*C*dfs(K-1,A,B+1,C)/sum;
		res+=1.0*dfs(K-1,A,B,C)/sum+1.0/sum;
	}
	else
	{
		if(A>0)res+=1.0*A*dfs(K-1,A-1,B,C)/sum;
		if(B>0)res+=1.0*B*dfs(K-1,A+1,B-1,C)/sum;
		if(C>0)res+=1.0*C*dfs(K-1,A,B+1,C-1)/sum;
		res+=1.0*dfs(K-1,A,B,C)/sum+1.0/sum;
	}
	// printf("%d %.10f\n",K,res);
	return tmp=res;
}
void solve()
{
	int K,A,B,C;
	scanf("%d%d%d%d",&K,&A,&B,&C);
	printf("%.2f\n",dfs(K,A,B,C));

}
int main()
{
	for(int i=0;i<=50;++i)
	for(int k=0;k<=7;++k)
	for(int l=0;l<=7;++l)
	for(int m=0;m<=7;++m)
	dp[i][k][l][m]=-1;

	int T;scanf("%d",&T);
	while(T--)solve();
}
/*
1
1 1 2 1
1
50 2 2 2
*/