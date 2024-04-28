#include<cstdio>
#define Fasdasd
const int maxn=5e3+5;
int n,m,a[maxn],b[maxn];
long long ans;
inline int abs(const int &a)
{
	return a<0?-a:a;
}
inline int min(const int &a,const int &b)
{
	return a<b?a:b;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{
		int mn=0x3f3f3f3f;
		for(int j=1;j<=m;++j)
			mn=min(abs(a[i]-b[j]),mn);
		ans+=mn;
	}
	printf("%lld\n",ans);
			
}
int main()
{
	#ifndef F
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
