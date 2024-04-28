#include<cstdio>
#define F
const int maxn=1e6+5;
int n,p,a[maxn];
long long ans,mx,sum,f[maxn],d[maxn],k[maxn];
void solve()
{
	scanf("%d%d",&n,&p);
	mx=-1e9;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		if(sum>mx)mx=sum;
		if(sum<0)sum=0;
		k[i]=mx%p;
	}
	ans=d[1]=k[1];
	mx=-1e9;
	for(int i=2;i<=n;++i)
	{
		if(d[i-1]+k[i-1]>mx)
			mx=d[i-1]+k[i-1];
		d[i]=mx;
		if(ans<mx)ans=mx%p; 
	}
	printf("%lld\n",ans);
}
int main()
{
	#ifndef F
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}

