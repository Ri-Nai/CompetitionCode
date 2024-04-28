#include<bits/stdc++.h>
using namespace std;
int dp[25][105][105],n,m,s,ans;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    memset(dp,0x3f,sizeof dp);
    dp[1][0][m]=0;ans=0x3f3f3f3f;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=s;++j)
            for(int k=m-j;~k;--k)
            {
                for(int l=1;l<=s;++l)
                    if(l*l<=k)dp[i][j+l][k-l*l]=min(dp[i][j+l][k-l*l],dp[i][j][k]+1);
                dp[i+1][j][m-j]=min(dp[i+1][j][m-j],dp[i][j][k]);
            }
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
            ans=min(ans,dp[i][s][j]);
    printf("%d\n",ans);
}