#include<cstdio>
#include<algorithm>
const int maxn=2e5+5;
int n,m,L,A[maxn];
bool check(int T)
{
	int now=1,s=0;
	for(int i=1;i<=m;++i)
	{
		while(now<=n&&A[now]-s<=T)++now;
		s=A[now-1];
		//printf("%d %d\n",T,now);
		if(now>n)return 1;
	}
	return 0; 
}
int main()
{
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	A[++n]=L;std::sort(A+1,A+n+1);
	int l=1,r=L,ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}