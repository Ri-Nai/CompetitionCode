#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e9+7;
int B[N],n,m,fail[N],dp[N];
int main()
{
	register int now,i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&B[i]);
		if(i==1)continue;
		int j=fail[i-1];
		while(j&&B[i]^B[j+1])j=fail[j];
		B[i]==B[j+1]&&(fail[i]=j+1);
	}
	printf("%d\n",dp[1]=m);
	for(i=2;i<=n;++i)
	{
		dp[i]=(1ll*dp[i-1]*m+m)%mod;
		for(j=1;j<=m;++j)
		{
			if(j==B[i])continue;
			k=fail[i-1];
			while(k&&B[k+1]^j)k=fail[k];
			dp[i]-=dp[k+(B[k+1]==j)];
			dp[i]<0&&(dp[i]+=mod);
		}
		printf("%d\n",dp[i]);
	}
}