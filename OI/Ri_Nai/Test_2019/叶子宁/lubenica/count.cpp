#include<cstdio>
#define F
int cnt[10];
void work(int a)
{
	do
	{
		++cnt[a%10];
		a/=10;
	}while(a);
}
void solve()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
		work(i);
	printf("%d\n",cnt[x]);
}
int main()
{
	#ifndef F
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
