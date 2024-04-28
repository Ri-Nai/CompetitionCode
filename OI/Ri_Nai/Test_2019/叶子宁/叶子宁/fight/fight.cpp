#include<cstdio>
#define Fasdasdasd 
const int maxn=1e5+5;
int n,m,p1,s1,s2,a[maxn],ans;
long long sum[maxn],mn=4e18;
inline long long abs(const long long &a)
{
	return a<0?-a:a;
}
void pre()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d%d%d%d",&m,&p1,&s1,&s2);
	a[p1]+=s1;
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1];
		if(i<=m)
			sum[i]+=1ll*a[i]*(m-i);
		else sum[i]+=1ll*a[i]*(i-m);
	}
}
void solve()
{
	pre();
	long long l=sum[m-1],r=sum[n]-sum[m];
	for(int i=1;i<=n;++i)
	{
		if(i<=m)
		{
			long long now=l+1ll*s2*(m-i);
			if(abs(now-r)<mn)mn=abs(now-r),ans=i;
		}
		else
		{
			long long now=r+1ll*s2*(i-m);
			if(abs(now-l)<mn)mn=abs(now-l),ans=i;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
6
2 3 2 3 2 3
4 6 5 2
6
1 1 1 1 1 16
5 4 1 1
*/
