#include<cstdio>
#include<cstring>
#define LL long long
LL dp[20][20][10],x,y;
int A[20];
LL dfs(int pos,int pre,int len,bool lmt,bool first)
{
	if(!pos)return pre%2!=len%2;
	if(!lmt&&~dp[pos][len][pre])return dp[pos][len][pre];
	int Up=lmt?A[pos]:9;LL res=0;
	for(int i=0;i<=Up;++i)
		if(first)
		{
			if(!i)res+=dfs(pos-1,0,0,lmt&&i==Up,1);
			else  res+=dfs(pos-1,i,1,lmt&&i==Up,0);
		}
		else
		{
			if(pre%2!=i%2)
			{
				if(pre%2==len%2)continue;
				res+=dfs(pos-1,i,1,lmt&&i==Up,0);
			}
			else res+=dfs(pos-1,i,len+1,lmt&&i==Up,0);
		}
	if(!lmt)dp[pos][len][pre]=res;
	return res;
}
LL solve(LL x)
{
	int len=0;
	while(x)A[++len]=x%10,x/=10;
	return dfs(len,0,0,1,1);
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	for(int i=1;i<=T;++i)
		scanf("%lld%lld",&x,&y),
		printf("Case #%d: %lld\n",i,solve(y)-solve(x-1));
}