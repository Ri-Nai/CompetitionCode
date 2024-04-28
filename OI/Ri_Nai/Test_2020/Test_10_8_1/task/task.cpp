#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define ToMin(A,B) ((B)<A)&&(A=B)
const int N=2e3+5,inf=0x3f3f3f3f;
int n,A[N],B[N];
namespace P30
{
	int ans=inf;
	void dfs(int now,int At,int Bt)
	{
		int stp=max(At,Bt);
		if(stp>=ans)return;
		if(now==n+1)
		{
			ans=stp;
			return;
		}
		if(At<=Bt)
		{
			dfs(now+1,At+A[now],Bt);
			dfs(now+1,Bt,Bt+B[now]);
		}
		else
		{
			dfs(now+1,At+A[now],At);
			dfs(now+1,At,Bt+B[now]);
		}
	}
	void Solve()
	{
		dfs(1,0,0);
		printf("%d\n",ans);
	}
}
namespace P70
{
	const int M=200*305;
	int dp[2][M];
	void Solve()
	{
		memset(dp,inf,sizeof dp);
		dp[0][A[1]]=0;dp[0][0]=B[1];
		int cur=0,mx=A[1];
		for(int i=2;i<=n;++i)
		{
			memset(dp[cur^1],inf,sizeof dp[cur]);
			for(int j=0;j<=mx;++j)
			{
				int k=dp[cur][j];
				if(k==inf)continue;
				if(k<=j)
				{
					ToMin(dp[cur^1][j],k+B[i]);
					ToMin(dp[cur^1][j+A[i]],j);
				}
				else//j更小
				{
					ToMin(dp[cur^1][k],k+B[i]);
					ToMin(dp[cur^1][j+A[i]],k);
				}
				mx=max(mx,j+A[i]);
			}
			cur^=1;
		}
		int ans=inf;
		for(int i=0;i<M;++i)
		{
			int t=max(i,dp[cur][i]);
			ToMin(ans,t);
		}
		printf("%d\n",ans);
	}
}
namespace P100
{
	int dp[2][2005][3005];
	void Solve()
	{
		memset(dp,0x3f,sizeof dp);
		dp[0][0][0]=dp[1][0][0]=0;
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=3000;++j)
			{
				ToMin(dp[0][i][A[i]],dp[0][i-1][j]+j);
				ToMin(dp[1][i][B[i]],dp[1][i-1][j]+j);
				if(B[i]<=j)ToMin(dp[0][i][j-B[i]],dp[0][i-1][j]+B[i]);
				else       ToMin(dp[1][i][B[i]-j],dp[0][i-1][j]+j);
				if(A[i]<=j)ToMin(dp[1][i][j-A[i]],dp[1][i-1][j]+A[i]);
				else       ToMin(dp[0][i][A[i]-j],dp[1][i-1][j]+j);

			}
		for(int i=0;i<=3000;++i)
			ans=min(ans,min(dp[0][n][i]+i,dp[1][n][i]+i));
		printf("%d\n",ans);
	}
}
int main()
{
	// FILE("task");
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&A[i],&B[i]);
	// if(n<=20)P30::Solve();
	// else P70::Solve();
	P100::Solve();
	FCLS();
}
/*
1.等慢的处理完,时间到慢的这个时间,让慢的去处理
2.自己先处理这个问题,时间到min(慢的,快的处理后)

时间储存太过麻烦,最坏情况下可能达到2000*3000,6e6
O(n*MxT) 70分可能勉强能冲

70分打完啦 100分怎么冲?

时间这个维度直接6e6,怎么看都不像是能冲的

虽然总时间巨大,但是等待时间最多3005
也就是说从上一状态转移过来的时间,最多只有3005个点(?)

但是存等待时间的时候,又要重新存下之前用过的时间(?)
反正不会///


考后:把存时间的东西改成存等待时间,也就是时间差,每次加的时候直接加上以前的时间就可以了
*/