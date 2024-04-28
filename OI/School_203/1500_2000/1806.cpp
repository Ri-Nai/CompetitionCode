#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int n;
LL A[N],sum[N<<1];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&A[i]),
		sum[i]=sum[i-1]^A[i];
	for(int i=0;i<=n;++i)
		sum[i+n+1]=sum[i];
	int Q;LL l,r;
	for(scanf("%d",&Q);Q--;)
	{
		scanf("%lld%lld",&l,&r);
		--l,--r;
		LL len=r-l+1;
		len%=n+1;
		l%=n+1;
		r=l+len;
		printf("%lld\n",sum[r]^sum[l]);
	}
}