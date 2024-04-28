#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2005,mod=1e9+7;
int X[maxn],Y[maxn],id[maxn],n,r,c;
LL fact[maxn<<8],dp[maxn],inv[maxn<<8];
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
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
bool cmp(int _,int __)
{
	return Y[_]==Y[__]?X[_]<X[__]:Y[_]<Y[__];
}
int main()
{
	scanf("%d%d%d",&r,&c,&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]),id[i]=i;
	X[++n]=r,Y[n]=c,id[n]=n,sort(id+1,id+n+1,cmp),fact[0]=1;
	for(int i=1;i<=r+c;++i)fact[i]=fact[i-1]*i%mod;
	inv[r+c]=qpow(fact[r+c],mod-2);
	for(int i=r+c-1;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i)
	{
		int u=id[i];
		dp[i]=COM(X[u]+Y[u]-2,X[u]-1);
		for(int j=1;j<i;++j)
		{
			int v=id[j];
			if(X[v]<=X[u])
			{
				dp[i]-=dp[j]*COM(X[u]+Y[u]-X[v]-Y[v],X[u]-X[v])%mod;
				dp[i]=(dp[i]+mod)%mod;
			}
		}
	}
	printf("%lld\n",dp[n]);
}