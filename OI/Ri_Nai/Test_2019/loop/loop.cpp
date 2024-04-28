#include<cstdio>
const int maxn=1e4+5;
int T,k,n,m,a[maxn];
long long s,sum,mx;
void work()
{
	int i,j;
	mx=0;
	scanf("%d%lld%d%d",&n,&s,&m,&k);
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<n;++i)
	{
		int now=i,sum=0;
		if(sum>mx)mx=sum;
		for(j=0;j<m;++j)
		{
			now+=k;
			if(now>=n)now-=n;
			sum+=a[now];
			if(sum>mx)mx=sum;
		}
	}
	printf("%lld\n",s-mx>=0?s-mx:0);
}
void solve()
{
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
		printf("Case #%d: ",i),
		work();
}
int main()
{
	
	solve();
	fclose(stdin);
	fclose(stdout);
}
