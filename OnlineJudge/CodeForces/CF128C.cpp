#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,mod=1e9+7;
typedef long long LL;
int n,m,k;
LL fact[maxn],dp[maxn],inv[maxn];
LL qpow(LL n,int p)
{
	LL res=1;
	while(p)
	{
		if(p&1)res=res*n%mod;
		n=n*n%mod;p>>=1;
	}
	return res;
}
LL COM(int n,int m)
{
	if(m>n)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);fact[0]=1;
	for(int i=1;i<maxn;++i)fact[i]=fact[i-1]*i%mod;
	inv[maxn-1]=qpow(fact[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
	printf("%lld\n",COM(n-1,k<<1)*COM(m-1,k<<1)%mod);
}