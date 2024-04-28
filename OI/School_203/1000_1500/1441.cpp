#include<cstdio>
#include<algorithm>
const int maxn=505;
int A[maxn],dp[maxn],n,m,mx,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    for(int i=n;i>=1;--i)
    {
        mx=0;
        for(int j=1;j<=i;++j)
        {
            if(A[i]>A[j]&&dp[j]>mx)mx=dp[j];
            else if(A[i]==A[j])
                {
                    dp[j]=mx+1;
                    if(i!=j&&2*dp[j]>ans)ans=dp[j]*2;
                    else if(i==j&&2*dp[j]-1>ans)ans=dp[j]*2-1;
                }
        }
    }
    printf("%d\n",ans);
}