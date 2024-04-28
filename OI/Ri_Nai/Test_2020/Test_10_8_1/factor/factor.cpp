#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e3+5,mod=1e4+7;
int a,b,k,n,m;
int inv[N],fact[N];
int Qpow(int n,int p)
{
	int res=1;
	for(;p;p>>=1,n=1ll*n*n%mod)
		if(p&1)res=1ll*res*n%mod;
	return res;
}
void init(int n)
{
	for(int i=fact[0]=1;i<=n;++i)fact[i]=1ll*i*fact[i-1]%mod;
	inv[n]=Qpow(fact[n],mod-2);
	for(int i=n-1;i>=0;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
	if(m>n)return 0;
	return 1ll*fact[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
	// FILE("factor");
	cin>>a>>b>>k>>n>>m;init(k);
	printf("%d\n",Qpow(a,n)*Qpow(b,m)%mod*C(k,n)%mod);
	FCLS();
}