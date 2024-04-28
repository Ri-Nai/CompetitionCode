#include<cstdio>
#include<cstring>
#define LL long long
LL l, r;
int len;
int num[30];
LL dp[12][2][2][4];
LL dfs(int pos, int _4, int _8, int cnt, int pre, int lmt)
{
    if(_4&&_8)return 0;
    if(pos==0)return cnt==3;
    if(!lmt&&~dp[pos][_4][_8][cnt])return dp[pos][_4][_8][cnt];
    LL res=0;
    int Up=lmt?num[pos]:9;
    for(int i=pos==len?1:0;i<=Up;++i) 
        if(cnt==3)res+=dfs(pos-1,_4||i==4,_8||i==8,3,i,lmt&&i==num[pos]);
        else res+=dfs(pos-1,_4||i==4,_8||i==8,i==pre?cnt+1:1,i,lmt&&i==num[pos]);
    if(!lmt)dp[pos][_4][_8][cnt]=res;
    return res;
}
LL solve(LL n) 
{
    if(n==(LL)1e10-1)return 0;
    len=0;
    while(n)num[++len]=n%10,n/=10;
    return dfs(len,0,0,0,-1,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",solve(r)-solve(l-1));
    return 0;
}