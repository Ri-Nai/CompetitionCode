#include<cstdio>
#include<cstring>
#define LL long long
LL dp[30][1050][10],x,y;
int A[30],B[30],K;
int update(int s,int size,int num)
{
	if(size-K+1<=0)return s|(1<<num);
	return (s^(1<<B[size-K+1]))|(1<<num);
}
LL dfs(int pos,int s,bool lmt,bool first,int tot)
{	
	if(!pos)return 1;
	if(!lmt&&!first&&~dp[pos][s][K])return dp[pos][s][K];
	int Up=lmt?A[pos]:9;LL res=0;
	for(int i=0;i<=Up;++i)
	{
		if(first)
		{
			if(!i)res+=dfs(pos-1,0,lmt&&i==Up,1,0);
			else
			{
				B[tot+1]=i;int k=update(s,tot+1,i);
				res+=dfs(pos-1,k,lmt&&i==Up,0,tot+1);
			}
		}
		else if(((1<<i)&s)==0)
		{
			B[tot+1]=i;int k=update(s,tot+1,i);
			res+=dfs(pos-1,k,lmt&&i==Up,0,tot+1);
		}
	}
	if(!lmt&&!first)dp[pos][s][K]=res;
	return res;
}
LL solve(LL x)
{
	int len=0;
	while(x)A[++len]=x%10,x/=10;
	return dfs(len,0,1,1,0);
}
int main()
{
	memset(B,12,sizeof B);
	memset(dp,-1,sizeof dp);
	while(~scanf("%lld%lld%d",&x,&y,&K))
		printf("%lld\n",solve(y)-solve(x-1));
}