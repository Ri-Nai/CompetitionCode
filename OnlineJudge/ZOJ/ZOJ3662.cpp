#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005,mod=1e9+7;
int n,m,K,lcm[maxn][maxn],A[maxn],tot=0,dp[2][maxn][maxn];
inline int LCM(const int &a,const int &b){return a/__gcd(a,b)*b;}
int main()
{
	// freopen("1.in","r",stdin);
	// freopen("wo.out","w",stdout);
	for(int i=1;i<=1000;++i)
		for(int j=1;j<=1000;++j)
			lcm[i][j]=LCM(i,j);
	while(~scanf("%d%d%d",&n,&m,&K))
	{
		tot=0;
		for(int i=1;i<=m;++i)
			if(m%i==0)A[++tot]=i;
		for(int i=0;i<=n;++i)
			for(int j=1;j<=tot;++j)
				dp[0][i][A[j]]=0;
		dp[0][0][1]=1;
		for(int now=1;now<=K;++now)
		{
			for(int i=0;i<=n;++i)
				for(int j=1;j<=tot;++j)
					dp[now&1][i][A[j]]=0;
			for(int i=now-1;i<=n;++i)
				for(int j=1;j<=tot;++j)//最小公倍数的最小公倍数还是最小公倍数
					if(dp[now&1^1][i][A[j]])
						for(int k=1;k<=tot;++k)
						{
							int Lcm=lcm[A[j]][A[k]];
							int sum=i+A[k];
							if(m%Lcm==0&&sum<=n)
								(dp[now&1][sum][Lcm]+=dp[now&1^1][i][A[j]])%=mod;
						}
		}
		printf("%d\n",dp[K&1][n][m]);
	}
}