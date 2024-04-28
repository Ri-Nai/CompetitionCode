#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int k,m,n,A[N],dp[N];
int main()
{
	cin>>m>>k>>n;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	sort(A+1,A+n+1);n=unique(A+1,A+n+1)-A-1;
	for(int i=1,p=1,mn=1e9;i<=n;++i)
	{
		while(A[p]+k<=A[i])mn=min(mn,dp[p-1]-A[p]+1),++p;
		dp[i]=min(mn+A[i],dp[p-1]+k);
	}cout<<dp[n];
}