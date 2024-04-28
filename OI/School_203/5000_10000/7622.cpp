#include<bits/stdc++.h>
using namespace std;
#define Add(x,y) ((x=(y))>=mod&&(x-=mod))
const int N=2005,mod=1e9+9;
int n,m,A[N],B[N],inv[N],fact[N],f[N],ans;
int Qpow(int p,int n)
{
	int res=1;
	for(;n;n>>=1,p=1ll*p*p%mod)
		if(n&1)res=1ll*res*p%mod;
	return res;
}
inline int C(int n,int m)
{
	return 1ll*fact[n]*inv[n-m]%mod*inv[m]%mod;
}
void Pre()
{
	fact[0]=f[0]=1;
	for(int i=1;i<N;++i)fact[i]=1ll*fact[i-1]*i%mod;
	inv[N-1]=Qpow(fact[N-1],mod-2);
	for(int i=N-2;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n+m&1)return !puts("0");m=n+m>>1;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)scanf("%d",&B[i]);
	Pre();sort(A+1,A+n+1);sort(B+1,B+n+1);
	for(int i=1,now=0;i<=n;++i)
	{
		while(now<n&&B[now+1]<A[i])++now;
		for(int j=i;j;--j)
			Add(f[j],(1ll*f[j-1]*max(now-j+1,0)+f[j])%mod);
	}
	for(int i=m,flag=1;i<=n;++i,flag=-flag)
	{
		ans+=1ll*f[i]*fact[n-i]%mod*C(i,m)*flag%mod;
		flag==-1&&ans<0&&(ans+=mod);
		flag==1&&ans>=mod&&(ans-=mod);
	}
	printf("%d\n",ans);
}