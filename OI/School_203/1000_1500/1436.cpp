#include<cstdio>
#include<algorithm>
const int maxn=2e4+5;
int n,m,A[maxn],B[maxn];
int dis(int from,int L,int R)
{
	if(from<=L)return R-from;
	if(from>=R)return from-L;
	return std::min(from-L,R-from)+R-L;
}
bool check(int T)
{
	int L=1,R=1;
	for(int i=1;i<=n;++i)
	{
		while(R<=m&&dis(A[i],B[L],B[R])<=T)++R;
		L=R;
	}
	return R>m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=m;++i)scanf("%d",&B[i]);
	int l=0,r=1e8,mid,ans;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			ans=mid,
			r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}