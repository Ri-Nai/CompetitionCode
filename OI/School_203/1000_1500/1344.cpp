#include<cstdio>
#include<cstring>
#include<algorithm>
const int M=505;
int n,k,l[M][M],r[M][M],
block[M][M],dp[M][M],a[M];
int main ()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            l[i][j]=l[i][j-1]+(a[j]-a[i]);
    for(int i=n;i>=1;--i)
        for(int j=n;j>=i+1;--j)
            r[i][j]=r[i+1][j]+(a[j]-a[i]);
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
        {
            block[i][j]=0x7f7f7f7f;
            for(int k=i;k<=j;++k)
                block[i][j]=std::min(block[i][j],r[i][k]+l[k][j]);
        }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;++i)
        dp[0][i]=0;
    for(int i=1;i<=n;++i)    
        for(int j=1;j<=k;++j)
            for(int p=1;p<=i;++p)
                dp[i][j]=std::min(dp[i][j],dp[p-1][j-1]+block[p][i]);
            
    printf("%d\n",dp[n][k]);
}