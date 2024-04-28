#include<cstdio>
#include<algorithm>
const int maxn=1e4+5;
int k,T,V,ans,v[maxn],m[maxn],dp[maxn];
int main()
{
    scanf("%d%d",&V,&T);
    while(T--)
    {
        scanf("%d",&k);
        for(int i=1;i<=k;++i)
            scanf("%d%d",&m[i],&v[i]);
        for(int i=V;~i;--i)
            for(int j=1;j<=k;++j)
                if(i-m[j]>=0)dp[i]=std::max(dp[i],dp[i-m[j]]+v[j]); 
    }
    printf("%d\n",dp[V]);
}