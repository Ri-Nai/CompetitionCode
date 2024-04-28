#include<queue>
#include<vector>
#include<cstdio>
#include<bitset>
#include<functional>
const int maxn=300;
std::bitset<200000>dp;
int n,val[maxn],m;
std::priority_queue<int,std::vector<int>,std::greater<int> >Q;
void solve()
{
	dp.reset();dp[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&val[i]),
		Q.push(val[i]);
	scanf("%d",&m);
	while(Q.size()>1)
	{
		int val1=Q.top();Q.pop();
		int val2=Q.top();Q.pop();
		Q.push(val1+val2);
		dp|=dp<<val2-val1;
		m-=val1;
	}
	Q.pop();
	if(m<0)puts("No");
	else if(m>=200000)puts("No");
	else puts(dp[m]?"Yes":"No");
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}