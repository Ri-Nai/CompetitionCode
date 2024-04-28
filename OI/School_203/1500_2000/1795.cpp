#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int A[N],n,lmx[N],rmx[N];
long long ans;
int main()
{
	scanf("%d",&n);int cnt=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	A[0]=A[n+1]=1e9;
	for(int i=1;i<=n;++i)
		lmx[i]=max(lmx[i-1],A[i]);
	for(int i=n;i>=1;--i)
		rmx[i]=max(rmx[i+1],A[i]);
	for(int i=2;i<n;++i)
		ans+=min(lmx[i],rmx[i])-A[i];
	printf("%lld\n",ans);
}