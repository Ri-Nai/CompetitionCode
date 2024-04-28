#include<cstdio>
#include<cmath>
#define ULL unsigned long long 
const ULL mod=1e10;
ULL A[55];
int n;
void work(int n)
{
	for(int i=1;i<=50;++i)A[i]<<=n;
	for(int i=1;i<=50;++i)A[i+1]+=A[i]/mod,A[i]%=mod;
}
int main()
{
	scanf("%d",&n);
	printf("%d",(int)(log10(2)*n)+1);
	A[1]=1;
	while(n>=30)work(30),n-=30;if(n)work(n);
	--A[1];
	for(int i=50;i;--i)
	{
		if(i%5==0)puts("");
		printf("%010llu",A[i]);
	}
}