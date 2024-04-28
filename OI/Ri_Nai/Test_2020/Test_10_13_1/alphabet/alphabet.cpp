#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5,mod=1e9+7;
int n,m,k,dp[M],lst[26];
char s[N];
int main()
{
	cin>>n>>k>>s+1;
	m=strlen(s+1);
	dp[0]=1;
	for(int i=1;i<=m;++i)
	{
		int p=s[i]-'a';
		dp[i]=(dp[i-1]<<1)%mod;
		if(lst[p])dp[i]=(dp[i]-dp[lst[p]-1]+mod)%mod;
		lst[p]=i;
	}
	for(int i=m+1;i<=n+m;++i)
	{
		int mn=1e9,p;
		for(int j=0;j<k;++j)
			if(lst[j]<mn)mn=lst[p=j];
		dp[i]=(dp[i-1]<<1)%mod;
		if(lst[p])dp[i]=(dp[i]-dp[lst[p]-1]+mod)%mod;
		lst[p]=i;
	}
	printf("%d\n",dp[n+m]);
}