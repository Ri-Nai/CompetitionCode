#include<cstdio>
#include<cstring>
int dp[20][10000],x,y,Fx,A[20];
int dfs(int pos,int Fy,bool lmt)
{
	if(!pos)return Fy<=Fx;
	if(!lmt&&~dp[pos][Fx-Fy])return dp[pos][Fx-Fy];
	int Up=lmt?A[pos]:9;int res=0;
	for(int i=0;i<=Up;++i)
	{
		int k=Fy+(i*(1<<pos-1));
		if(k>Fx)continue;
		res+=dfs(pos-1,k,lmt&&i==Up);
	}
	if(!lmt)dp[pos][Fx-Fy]=res;
	return res;
}
int solve(int x,int y)
{
	int len=0;Fx=0;
	for(int i=1;;++i)
	{
		Fx+=(1<<i-1)*(x%10),x/=10;
		if(!x)break;
	}
	while(y)A[++len]=y%10,y/=10;
	return dfs(len,0,1);
}
int main()
{
	int T;scanf("%d",&T);memset(dp,-1,sizeof dp);
	for(int i=1;i<=T;++i)
		scanf("%lld%lld",&x,&y),
		printf("Case #%d: %d\n",i,solve(x,y));
}