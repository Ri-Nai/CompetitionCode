#include<cstdio>
#include<bitset>
const int maxn=105;
std::bitset<10005>dp[maxn],ans;
int n;
void solve(int id)
{
	dp[id][0]=1;int x;
	while(scanf("%d",&x)&&~x)dp[id]|=dp[id]<<x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)solve(i);ans=dp[1];
	for(int i=2;i<=n;++i)ans&=dp[i];
	for(int i=10000;~i;--i)if(ans[i]){printf("%d\n",i);return 0;}
}
