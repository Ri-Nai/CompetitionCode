#include<bits/stdc++.h>
using namespace std;
long long tmp,dp[105][(1<<18)+5];
int n,m,A[20];
int main()
{
	scanf("%lld%d",&tmp,&m);dp[0][0]=1;
	while(tmp)A[n++]=tmp%10,tmp/=10;
	for(int i=1;i<(1<<n);++i)
	{
		bool vis[10]={};
		for(int j=0;j<n;++j)
		{
			if(i==(1<<j)&&!A[j])break;
			if(!(i&1<<j)||vis[A[j]])continue;
			vis[A[j]]=1;
			for(int k=0;k<m;++k)
				dp[(k*10+A[j])%m][i]+=dp[k][i^(1<<j)];
		}
	}
	printf("%lld\n",dp[0][(1<<n)-1]);
}