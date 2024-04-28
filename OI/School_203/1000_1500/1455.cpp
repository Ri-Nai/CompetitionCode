#include<cstdio>
#include<cstring>
const int maxn=2e5+5;
int n,m,k,A[maxn],cnt[maxn];
bool check(int t)
{
	memset(cnt,0,sizeof cnt);
	int l=0,r=1;
	while(r<=n)
	{
		++cnt[A[r]];while(r-l>t+k)--cnt[A[++l]];
		if(cnt[A[r]]>=t)return 1;++r;
	}
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
 	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			ans=mid,
			l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}