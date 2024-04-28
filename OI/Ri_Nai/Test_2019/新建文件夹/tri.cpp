#include<cstdio>
#define F
int T;
void solve()
{
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int sum=0;
		for(int i=1;i<a;++i)
			if(a%i==0)
				sum+=i;
		if(sum!=b)
			puts("NO");
		else
		{
			sum=0;
			for(int i=1;i<b;++i)
				if(b%i==0)
					sum+=i;
			if(sum!=a)
				puts("NO");
			else puts("YES");
		}
	}
}
int main()
{
	#ifndef F
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
