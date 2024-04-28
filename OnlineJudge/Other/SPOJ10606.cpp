#include<cstdio>
#include<cstring>
long long dp[20][60000],A[20],x,y;
bool judge(int s)
{
	int num[12],q=1;
	for(int i=0;i<=9;++i)
	{
		num[i]=s%3;s/=3;
		if(num[i])
			if(i%2==num[i]%2)return 0;
	}
	return 1;
}
int Get(int s,int id)
{
	int num[12],q=1;
	for(int i=0;i<=9;++i)
	{
		num[i]=s%3;s/=3;
		if(i==id)
		{
			++num[i];
			if(num[i]>2)num[i]-=2;
		}
	}s=0;
	for(int i=0;i<=9;++i)
		s+=q*num[i],q*=3;
	return s;
}
long long dfs(int pos,int s,bool lmt,bool first)
{
	if(!pos)return judge(s);
	if(!lmt&&~dp[pos][s])return dp[pos][s];
	int Up=lmt?A[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
		if(first&&!i)res+=dfs(pos-1,0,lmt&&i==Up,1);
		else res+=dfs(pos-1,Get(s,i),lmt&&i==Up,0);
	if(!lmt)dp[pos][s]=res;
	return res;
}
long long solve(long long num)
{
	int len=0;
	while(num)A[++len]=num%10,num/=10;
	return dfs(len,0,1,1);
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	while(T--)scanf("%lld%lld",&x,&y),printf("%lld\n",solve(y)-solve(x-1));
}