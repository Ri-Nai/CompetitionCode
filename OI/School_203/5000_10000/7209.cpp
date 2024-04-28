#include<cstdio>
#include<cstring>
#define LL long long
const int mod=1e7+7;
int A[70],len;
LL ans=1,n,dp[70][70];
LL dfs(int pos,int num,bool lmt)
{
	if(num<0)return 0;
	if(!pos)return !num;
	if(!lmt&&~dp[pos][num])return dp[pos][num];
	int Up=lmt?A[pos]:1;LL res=0;
	for(int i=0;i<=Up;++i)
		res+=dfs(pos-1,num-i,lmt&&i==Up);
	if(!lmt)dp[pos][num]=res;
	return res;
}
LL qpow(LL x,LL p)
{
	LL res=1;
	while(p)
	{
		if(p&1)res=res*x%mod;
		p>>=1;x=x*x%mod;
	}
	return res%mod;
}
int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%lld",&n);
	while(n)A[++len]=n&1,n>>=1;
	for(int i=1;i<=len;++i)
	{
		LL tmp=dfs(len,i,1);
		ans=(ans*qpow(i,tmp))%mod;
	}
	printf("%lld\n",ans);
}