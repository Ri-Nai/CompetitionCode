#include<bits/stdc++.h>
using namespace std;
int n,h,H,f[25],t[25],d[25],dp[5000],ans;
void pre()
{
	scanf("%d%d",&n,&h);h*=12;
	for(int i=1;i<=n;++i)scanf("%d",&f[i]);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	for(int i=2;i<=n;++i)scanf("%d",&t[i]),t[i]+=t[i-1];
}
void fishing()
{
    memset(dp,-1,sizeof dp);dp[0]=0;
	for(int i=1;i<=n;++i)
        for(int j=h;j>=0;--j)
            for(int k=0;k<=j-t[i];++k)
                if(~dp[j-t[i]-k])
                {
                    int fish=(2*f[i]-(k-1)*d[i])*k/2;
                    ans=max(dp[j-t[i]]=max(dp[j-t[i]],dp[j-k-t[i]]+fish),ans);
                }
    printf("%d\n",ans);
}  
int main()
{
    pre();
    fishing();
}