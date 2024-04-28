#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	n-=4;n/=2;
	int k=sqrt(1ll*n*n-4ll*m);
	int a=(k+n)/2,b=n-a;
	a+=2;b+=2;
	printf("%d %d\n",max(a,b),min(a,b));
}