#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m,dp[100005],ans;
struct $
{
    int A,B;
    bool operator < ($ _){return B>_.B;}
}A[1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&A[i].A);
    for(int i=1;i<=n;++i)scanf("%d",&A[i].B);
    std::sort(A+1,A+n+1);
    for(int i=1;i<=n;++i)
        for(int j=m;j>=1;--j)
            ans=std::max(ans,dp[j]=std::max(dp[j],dp[j-1]+std::max(0,A[i].A-A[i].B*(j-1))));
    printf("%d\n",ans);
}