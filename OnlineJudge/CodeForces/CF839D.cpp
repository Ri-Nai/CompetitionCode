#include<cstdio>
#define LL long long
const int maxn=1e6,mod=1e9+7;
int n,cnt[maxn+5];
LL ans,p[maxn+5],sum[maxn+5];
int read()
{
    int t=0,c;
    do c=getchar();while(c<48||c>57);
    while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
int main()
{
	n=read();p[0]=1;
	for(int i=1;i<=n;++i)++cnt[read()];
	for(int i=1;i<=maxn;++i)p[i]=(p[i-1]<<1)%mod;
	for(int i=maxn;i>1;--i)
	{
		LL now=0;
		for(int j=i;j<=maxn;j+=i)
			sum[i]-=sum[j],now+=cnt[j];
		if(now>0)
			sum[i]+=(now*p[now-1])%mod,
			sum[i]=(sum[i]%mod+mod)%mod;
		ans=(ans+sum[i]*i)%mod;
	}
	printf("%lld\n",ans);
}