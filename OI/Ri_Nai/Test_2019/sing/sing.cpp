#include<cstdio>
#include<cstring>
#define Fasdasdsa
const int maxn=1e5+5;
int n,a[maxn],sum,mx;
bool mark[maxn];
void work()
{
	scanf("%d",&n);
	mx=sum=0;
	memset(mark,0,sizeof mark);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<n;++i)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
			mark[i]=1,++sum;
	}
	for(int i=1,now;i<=n;++i)
	{
		now=0;
		if(mark[i])++now;
		if(i-2>=1&&i+1<=n&&mark[i-1])
			if(!(a[i-1]>a[i-2]&&a[i-1]>a[i+1]))
				++now;
			else --now;
		if(!mark[i-1]&&a[i-1]>a[i-2]&&a[i-1]>a[i+1])
			--now;
		if(i+2<=n&&i-1>=1&&mark[i+1])
			if(!(a[i+1]>a[i-1]&&a[i+1]>a[i+2]))
				++now;
			else --now;
		if(!mark[i+1]&&a[i+1]>a[i-1]&&a[i+1]>a[i+2])
			--now;
		if(now>mx)mx=now;
	}
	printf("%d\n",sum-mx);
}
void solve()
{
	int T;
	scanf("%d",&T);
	while(T--)
		work();
}
int main()
{
	#ifndef F
	freopen("sing.in","r",stdin);
	freopen("sing.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
3
6
1 1 4 5 1 4
7
1 9 1 9 8 1 0
10
2 1 4 7 4 8 3 6 4 7
*/
