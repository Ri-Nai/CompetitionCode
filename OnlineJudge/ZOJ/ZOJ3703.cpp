#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=55,maxm=1005,inf=0x3f3f3f3f;
int	n,T;
struct $
{
	int num,v,w;
	bool operator <(const $ &_){return w==_.w?(num==_.num?v<_.v:num<_.num):w<_.w;}
}A[maxn],dp[maxm],ans;
bool cmp($ _,$ __){return _.v<__.v;}
void solve()
{
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i].v);
	for(int i=1;i<=n;++i)scanf("%d",&A[i].w);
	std::sort(A+1,A+n+1,cmp);
	dp[0]=ans=($){0,0,0};
	for(int i=1;i<=T;++i)dp[i]=($){-inf,inf,-inf};
	for(int i=1;i<=n;++i)
	{
		for(int j=T;j>=A[i].v;--j)
		{
			$ pre=dp[j-A[i].v];
			$ now=($){pre.num+1,j+pre.v,pre.w+A[i].w};
			//ans=std::max(dp[j]=std::max(dp[j],now),ans);
			if(dp[j]<now)dp[j]=now;
			if(ans<dp[j])ans=dp[j];
		}
	}
	printf("%d %d %d\n",ans.w,ans.num,ans.v);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}