#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e9+7;
int B[N],n,m,fail[N],dp[N],now=1;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		B[i]=rd();
		if(i!=1)
		{
			int j=fail[i-1];
			while(j&&B[i]!=B[j+1])j=fail[j];
			fail[i]=B[i]==B[j+1]?j+1:0;
		}
		now=1ll*now*m%mod;
		dp[i]=dp[fail[i]]+now;
		dp[i]>=mod&&(dp[i]-=mod);
		printf("%d\n",dp[i]);
	}
}