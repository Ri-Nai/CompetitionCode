#include<bits/stdc++.h>
using namespace std;
typedef long long ago;
const int N=1005,mod=1e9+7;
int n,m,k,A[N],fact[N<<1],inv[N<<1],mx;
ago dp[N],ans;
ago Qpow(ago p,ago n)
{
	ago res=1;
	for(;n;n>>=1,p=p*p%mod)
		if(n&1)res=res*p%mod;
	return res;
}
inline int C(int n,int m)
{
	return 1ll*fact[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);fact[0]=1;
	for(int i=1;i<=m;++i)scanf("%d",&A[i]),mx=max(mx,A[i]+n);
	for(int i=1;i<=mx;++i)fact[i]=1ll*fact[i-1]*i%mod;
	inv[mx]=Qpow(fact[mx],mod-2);
	for(int i=mx-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<n;++i)
	{
		dp[i]=1;
		for(int j=1;j<=m;++j)
			(dp[i]*=C(A[j]+n-i-1,n-i-1))%=mod;
		ans+=(i&1?-1:1)*dp[i]*C(n,i)%mod;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}