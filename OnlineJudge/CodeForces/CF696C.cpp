#include<cstdio>
#define LL long long
const int mod=1e9+7;
LL qpow(LL n,LL p)
{
	LL res=1;
	while(p)
	{
		if(p&1)res=res*n%mod;
		n=n*n%mod;p>>=1;
	}
	return res;
}
int main()
{
	LL Down=2;bool flag=0;
	int k;scanf("%d",&k);
	for(int i=1;i<=k;++i)
	{
		LL x;scanf("%lld",&x);
		if(!(x&1))flag=1;
		Down=qpow(Down,x);
	}
	Down=Down*qpow(2,mod-2)%mod;
	if(flag)printf("%lld/%lld\n",(Down+1*)qpow(3,mod-2)%mod,Down);
	else printf("%lld/%lld\n",(Down-1+mod)*qpow(3,mod-2)%mod,Down);
}