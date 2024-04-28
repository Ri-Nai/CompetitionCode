#include<cstdio>
#include<algorithm>
const int maxn=1e5+5;
int n,A[maxn];
long long ans,sum;
void solve()
{
	sum=0;ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	std::sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
		sum+=A[i],
		ans+=1ll*i*A[i]-sum;
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}