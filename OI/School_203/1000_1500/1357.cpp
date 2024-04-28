#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=2e5+5;
int n,a[20][20],dp[2][maxn],bit[2][maxn],res[maxn],tot[2],now,last,ans;
void dfs(int id,int k,int p,int sum)
{
    if(k>=n)
    {
        bit[now][++tot[now]]=p;
        res[tot[now]]=sum;
        return ;
    }
    dfs(id,k+2,p|(1<<k),sum+a[id][k]);
    dfs(id,k+1,p,sum);
}
 
void DP()
{
    for(int k=1;k<=n;++k)
    {
        now=k&1,last=now^1;tot[now]=0;
        dfs(k,0,0,0);
        memset(dp[now],0,sizeof dp[now]);
        for(int i=1;i<=tot[now];++i)
            for(int j=1;j<=tot[last];++j)
                if(!(bit[now][i]&bit[last][j]))dp[now][i]=std::max(dp[now][i],dp[last][j]+res[i]);
    }
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&a[i][j]);
    tot[0]=1;DP();ans=0;
    for(int i=1;i<=tot[now];++i)
        ans=std::max(ans,dp[now][i]);
    printf("%d\n",ans);
}