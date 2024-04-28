#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,mod=1e9+7;
int inv[N],fact[N];
int n,r1,r2,r3,s1[N],s2[N],s3[N],cnt[4];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
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
	for(int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
inline int C(int n,int m)
{
	if(m>n)return 0;
	return 1ll*fact[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
	n=rd();
	r1=rd();scanf("%s",s1+1);
	r2=rd();scanf("%s",s2+1);
	r3=rd();scanf("%s",s3+1);
	for(int i=1;i<=n;++i)
		++cnt[s1[i]^s2[i]|(s1[i]^s3[i])<<1];
	
}