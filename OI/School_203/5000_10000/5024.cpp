#include<bits/stdc++.h>
using namespace std;
const int m=4,K=5,M=1e5+5;
typedef long long ago;
int Q,C[K],A[K];
ago ans,dp[M];
int main()
{
	for(int i=0;i<m;++i)scanf("%d",&C[i]);
	dp[0]=1;scanf("%d",&Q);
	for(int j=0;j<m;++j)
		for(int i=1;i<M;++i)
			if(i>=C[j])dp[i]+=dp[i-C[j]];
	for(int i=1,S;i<=Q;++i)
	{
		for(int j=0;j<m;++j)scanf("%d",&A[j]);
		scanf("%d",&S);ans=dp[S];
		for(int j=1;j<16;++j)
		{
			bool flag=0;ago tmp=0;
			for(int k=0;k<m;++k)
				if(1<<k&j)tmp+=A[k]*C[k]+C[k],flag^=1;
			if(tmp>S)continue;
			ans+=(flag?-1:1)*dp[S-tmp];
		}
		printf("%lld\n",ans);
	}
}