#include<cstdio>
const int maxn=2e5+5,k=1e5;
int n,m,A[maxn],sum[maxn],pos;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		if(A[i]==m)pos=i;
	}
	int now=0;
	for(int i=pos;i>=1;--i)
	{
		if(A[i]>m)++now;
		else if(A[i]<m)--now;
		++sum[k+now];
	}now=0;int ans=0;
	for(int i=pos;i<=n;++i)
	{
		if(A[i]>m)++now;
		else if(A[i]<m)--now;
		ans+=sum[k-now];
	}
	printf("%d\n",ans);
}