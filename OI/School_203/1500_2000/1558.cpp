#include<cstdio>
#include<algorithm>
#define LL long long
LL n,m,x,A[100005],sum,ans;
int main()
{
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&A[i]),sum+=A[i];
	if(m-sum>=0)puts("0");
	else
	{
		sum-=m;int t=n;
		std::sort(A+1,A+n+1);
		for(int i=1;i<=n;++i)
		{
			LL k=sum/t;
			if(A[i]<k)ans+=A[i]*A[i],sum-=A[i];
			else ans+=k*k,sum-=k;--t;
		}
		printf("%lld\n",ans);
	}
}