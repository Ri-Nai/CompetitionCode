#include<cstdio>
void solve()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	int k=(100-p)*m/100;
	int kk=m-k;
	if(n-m<0)puts("0");
	else printf("%d\n",(n-m)/kk+1);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}