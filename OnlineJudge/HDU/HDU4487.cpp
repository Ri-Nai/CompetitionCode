#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
double dp[2][210][210];
double l,r,s;
int n,step;
void solve()
{
    scanf("%d%d",&step,&n);
    scanf("%lf%lf",&l,&r);
    s=1-l-r;memset(dp,0,sizeof dp);
    int last=0,cur;
    dp[last][100][100]=1;
    for(int i=1;i<=n;++i)
    {
        cur=last^1;
        for(int j=100-i;j<=100+i;++j)
            for(int k=std::max(j,100);k<=100+i;++k)
                if(j==k)
                    dp[cur][j][k]=dp[last][j][k]*s+dp[last][j-1][k-1]*r+dp[last][j-1][k]*r;
                else 
                    dp[cur][j][k]=dp[last][j][k]*s+dp[last][j-1][k]*r+dp[last][j+1][k]*l;
        last=cur;
    }
    double ans=0;
    for(int i=100-n;i<=100+n;++i)
        for(int j=100;j<=100+n;++j)
            ans+=dp[cur][i][j]*(j-100);
    printf("%d %.4lf\n",step,ans);
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)solve();
}