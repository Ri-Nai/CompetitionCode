#include<cstdio>
#include<cstring>
const int mod=2520;
long long dp[20][3000][50],A[20],x,y,id[3000],tot;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){if(b==0)return a;return a/gcd(a,b)*b;}
long long dfs(int pos,int rest,int LCM,bool lmt)
{
	if(!pos)return rest%LCM==0;
	if(!lmt&&~dp[pos][rest][id[LCM]])return dp[pos][rest][id[LCM]];
	int Up=lmt?A[pos]:9;long long res=0;
	for(int i=0;i<=Up;++i)
		res+=dfs(pos-1,(rest*10+i)%mod,lcm(LCM,i),lmt&&i==Up);
	if(!lmt)dp[pos][rest][id[LCM]]=res;
	return res;
}
long long solve(long long num)
{
	int len=0;long long res=0;
	while(num)A[++len]=num%10,num/=10;
	return dfs(len,0,1,1);
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	for(int i=1;i<=mod;++i)if(mod%i==0)id[i]=++tot;
	for(int i=1;i<=T;++i)
		scanf("%lld%lld",&x,&y),
		printf("%lld\n",solve(y)-solve(x-1));
}