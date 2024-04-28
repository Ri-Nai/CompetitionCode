#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
const int maxn=1e5+5,maxm=1e3+5,mod=1e9+7;
int n,m,len,A[maxn],B[maxn];
LL ans=0,dp[maxm][maxm];
void Add(int x,int y,int len){while(x<maxm)(dp[x][len]+=y)%=mod,x+=x&-x;}
LL sum(int x,int len){LL res=0;while(x)(res+=dp[x][len])%=mod,x-=x&-x;return res;}
void in_put()
{
	memset(dp,0,sizeof dp);ans=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	std::sort(B+1,B+n+1);len=std::unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=std::lower_bound(B+1,B+len+1,A[i])-B;
}
void solve(int cas)
{
	in_put();
	for(int i=1;i<=n;++i)
	{
		Add(A[i],1,1);
		for(int j=2;j<=i&&j<=m;++j)
			Add(A[i],sum(A[i]-1,j-1),j);
	}
	printf("Case #%d: %lld\n",cas,sum(n,m));
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}