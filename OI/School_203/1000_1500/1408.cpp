#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=105;
struct $
{
	int t,pos;
	bool operator <($ _)const{return pos<_.pos;}
}A[maxn];
int n,T,dp[maxn][maxn],ans;
void in_put()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)scanf("%d",&A[i].t);
	for(int i=1;i<=n;++i)scanf("%d",&A[i].pos);
	std::sort(A+1,A+n+1);memset(dp,0x7f,sizeof dp);
	dp[1][1]=A[1].t;
}
int main()
{
	in_put();
	for(int i=2;i<=n;++i)
	{
		dp[i][1]=std::min(A[i].t,dp[i-1][1]+A[i].pos-A[i-1].pos);
        for(int j=2;j<=i;++j)
            dp[i][j]=A[i].pos-A[i-1].pos+std::min(dp[i-1][j],dp[i-1][j-1]+A[i].t);
        for(int j=1;j<=i;++j)
            if(dp[i][j]<=T&&j>ans)ans=j;
	}
	printf("%d\n",ans);
}