#include<cstdio>
int n,h,A[2005];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),A[i]=h-A[i];
	long long ans=1,mod=1e9+7;
	for(int i=1;i<=n+1;++i)
	{
		int t=A[i]-A[i-1];
		if(t<-1||t>1){puts("0");return 0;}
		if(t==0)ans*=A[i]+1;
		if(t==-1)ans*=A[i-1];
		ans%=mod;
	}
	printf("%lld\n",ans);
}