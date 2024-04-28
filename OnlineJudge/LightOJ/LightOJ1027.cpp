#include<cstdio>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve(int id)
{
	printf("Case %d: ",id);
	int n;scanf("%d",&n);
	int sum=0,tot=0;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(x>0)++tot,sum+=x;
		else sum+=-x;
	}
	if(!tot)puts("inf");
	else
	{
		int t=gcd(sum,tot);
		printf("%d/%d\n",sum/t,tot/t);
	}
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}