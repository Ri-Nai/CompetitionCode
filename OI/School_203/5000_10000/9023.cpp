#include<bits/stdc++.h>
using namespace std;
long long Sqr(int x)
{
	return 1ll*x*x;
}
int n,m,k;long long now;
void solve(int Cas)
{
	scanf("%d%d%d",&n,&m,&k);
	double ans=0;long long tot=Sqr(1ll*n*m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int a=i-1,b=j-1,c=n-i,d=m-j;
			now=Sqr(a*m)+Sqr(b*n)+Sqr(c*m)+Sqr(d*n)-
				Sqr(a*b)-Sqr(a*d)-Sqr(c*b)-Sqr(c*d);
			ans+=1-pow(1.0*now/tot,k);
		}
	}
	printf("Case #%d: %.f\n",Cas,ans);
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}