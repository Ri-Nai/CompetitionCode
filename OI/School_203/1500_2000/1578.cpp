#include<cstdio>
long long F[85]={1,1,2},n;
int main()
{
	scanf("%lld",&n);
	for(int i=3;i<=80;++i)F[i]=F[i-1]+F[i-2];
	for(int i=80;i;--i)
	{
		if(n==F[i])
		{
			printf("%lld\n",n);
			break;
		}
		if(n>F[i])n-=F[i];
	}
}