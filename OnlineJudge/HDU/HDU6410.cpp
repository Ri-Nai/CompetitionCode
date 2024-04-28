#include<cstdio>
#define LL long long
const int HD=1e9+7,maxn=105;
int L[maxn],R[maxn],mxR,mxL;
LL qpow(LL x,int p)
{
	LL res=1;
	while(p)
	{
		if(p&1)res=res*x%HD;
		p>>=1;x=x*x%HD;
	}
	return res;
}
LL Sum(LL L,LL R)
{
	if(L>R)return 0ll;
	return (L+R)*(R-L+1)/2;
}
void solve()
{
	int n;scanf("%d",&n);
	mxL=mxR=0;
	LL ans=0,tot=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&L[i],&R[i]);
		if(L[i]>mxL)mxL=L[i];
		if(R[i]>mxR)mxR=R[i];
		tot=tot*(R[i]-L[i]+1)%HD;
	}
	for(int i=mxL;i<=mxR;++i)
	{
		LL now=1,pre=1;
		for(int j=1;j<=n;++j)
		{
			LL Upn,Upp;Upn=Upp=R[j];
			if(i<R[j])Upn=i;if(i-1<R[j])Upp=i-1;
			now=now*Sum(i-Upn+1,i-L[j]+1)%HD;
			pre=pre*Sum(i-Upp+1,i-L[j]+1)%HD;
		}
		ans+=now-pre+HD;ans%=HD;
	}
	ans=ans*qpow(tot,HD-2)%HD;
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}