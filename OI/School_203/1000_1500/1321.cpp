#include<cstdio>
const int maxn=1e5+5;
int n,A[maxn],tot=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),tot+=(A[tot]==x);
	printf("%d\n",n-tot+1);
}