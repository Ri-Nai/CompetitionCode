#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1<<16;
int n,num[M][26],dp[M];
char s[N];
int main()
{
	scanf("%d",&n);
	memset(dp,0x3f,sizeof dp);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		dp[1<<i]=strlen(s);
		for(int j=0;j<dp[1<<i];++j)
			++num[1<<i][s[j]-'a'];
	}int m=(1<<n)-1;
	for(int i=1;i<=m;++i)
	{
		int lst=i&-i,now=i^lst,sum=0;
		if(now)for(int j=0;j<26;++j)
			sum+=(num[i][j]=min(num[lst][j],num[now][j]));
		else sum=dp[1<<i];
		for(int j=(i-1)&i;j;j=(j-1)&i)
			dp[i]=min(dp[i],dp[j]+dp[j^i]-sum);
	}
	printf("%d\n",dp[m]+1);
}