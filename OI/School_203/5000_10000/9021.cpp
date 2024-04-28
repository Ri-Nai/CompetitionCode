#include<stdio.h>
#include<string.h>
#define LL long long
int n,A[20];LL dp[2][2][20];
LL dfs(int pos,bool pre1,bool pre2,bool lmt)
{
	if(pos==0)return 1;
	LL &tmp=dp[pre1][pre2][pos];
	if(!lmt&&~tmp)return tmp;
	int Up=lmt?A[pos]:9;LL res=0;
	for(int i=0;i<=Up;++i)
	{
		if(pre1&&pre2&&i==6)continue;
		res+=dfs(pos-1,i==6,pre1,lmt&&i==Up);
	}
	if(!lmt)tmp=res;return res;
}
bool check(LL m)
{
	int len=0;LL tmp=m;
	while(m)A[++len]=m%10,m/=10;
	return tmp-dfs(len,0,0,1)+1>=n;
}
void solve()
{
	scanf("%d",&n);
	LL L=1,R=1e18,ans=0;
	while(L<=R)
	{
		LL mid=L+R>>1;
		if(check(mid))
			ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	memset(dp,-1,sizeof dp);
	while(T--)solve();
}