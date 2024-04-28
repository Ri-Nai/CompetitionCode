#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
bool Nai;
const int N=1e6+5,M=105,mod=1e9+7;
int A[N],n,m,dp[N],pre[N][M],fail[N];
void Build_Fail()
{
	for(int now=1;now<=n;++now)
		for(int i=0;i<m;++i)
		{
			int &nxt=pre[now][i];
			if(nxt)fail[nxt]=pre[fail[now]][i];
			else nxt=pre[fail[now]][i];
		}
}
bool Ri;int main()
{
	// printf("%f MB\n",(&Ri-&Nai)/1024.0/1024);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),--A[i];
	for(int i=1;i<=n;++i)pre[i-1][A[i]]=i;
	Build_Fail();printf("%d\n",dp[1]=m);
	for(int i=2;i<=n;++i)
	{
		dp[i]=(1ll*dp[i-1]*m+m)%mod;
		for(int j=0;j<m;++j)
		{
			if(j==A[i])continue;
			dp[i]-=dp[pre[i-1][j]];
			dp[i]<0&&(dp[i]+=mod);
		}
		printf("%d\n",dp[i]);
	}

}