#include<cstdio>
#include<algorithm>
using std::abs;
int mon[5005],tree[5005],n,m;
long long dp[2][5005];
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&mon[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&tree[i]);
    std::sort(mon+1,mon+n+1);
    std::sort(tree+1,tree+m+1);
    dp[1][1]=abs(mon[1]-tree[1]);
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;++j)
        {
            if(j==1)
                dp[i&1][1]=dp[i&1^1][1]+abs(mon[i]-tree[j]);
            else if(i==j)
                dp[i&1][j]=dp[i&1^1][j-1]+abs(mon[i]-tree[j]);
            else dp[i&1][j]=std::min(dp[i&1^1][j],dp[i&1^1][j-1])+abs(mon[i]-tree[j]);
        }
    printf("%lld\n",dp[n&1][m]);
}
