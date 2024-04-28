#include<cstdio>
#include<algorithm>
const int maxn=35;
double dp[2][maxn][maxn];
bool vis[2][maxn][maxn];
double dfs1(int a,int b)
{
    if(b>21)return 1;
    if(vis[1][a][b])return dp[1][a][b];
    vis[1][a][b]=1;
    dp[1][a][b]=a>b;
    double tmp=0;
    for(int i=1;i<10;++i)
        tmp+=dfs1(a,b+i)/13;
    tmp+=dfs1(a,b+10)*4/13;
    return dp[1][a][b]=std::min(dp[1][a][b],tmp);
}
double dfs0(int a,int b)
{
    if(a>21)return 0;
    if(vis[0][a][b])return dp[0][a][b];
    vis[0][a][b]=1;
    dp[0][a][b]=dfs1(a,b);
    double tmp=0;
    for(int i=1;i<10;++i)tmp+=dfs0(a+i,b)/13;
    tmp+=dfs0(a+10,b)*4/13;
    return dp[0][a][b]=std::max(dp[0][a][b],tmp);
}
int to(char c)
{
    if(c=='A')return 1;
    if(c>='0'&&c<='9')return c-'0';
    return 10;
}
void solve()
{
    char s[5];
    scanf("%s",s);
    int a=to(s[0])+to(s[1]),b=to(s[2])+to(s[3]);
    double ans=dfs0(a,b);
    if(ans>0.5)puts("YES");
    else puts("NO");
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)solve();
}