#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
LL fact[maxn],inv[maxn],ans;
int n,m,sum[maxn];char s[maxn];
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
	if(m>n||n<0)return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);fact[0]=1;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]^=48);
	for(int i=1;i<maxn;++i)fact[i]=fact[i-1]*i%mod;
	inv[maxn-1]=qpow(fact[maxn-1],mod-2);LL now=1;
	for(int i=maxn-2;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i,now=now*10%mod)
		ans=(ans+now*(COM(n-i-1,m-1)*1ll*sum[n-i]%mod+COM(n-i,m)*1ll*s[n-i+1]%mod)%mod)%mod;
	printf("%lld\n",ans);
}