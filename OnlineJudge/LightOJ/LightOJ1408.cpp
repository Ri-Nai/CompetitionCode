#include<cstdio>
#include<cmath>
void solve(int id)
{
	double p,q;int k1,k2;
	scanf("%lf%d%d",&p,&k1,&k2);q=1-p;
	printf("Case %d: ",id);
	if(p<1e-9)printf("%d\n",k1);
	else if(q<1e-9)printf("%d\n",k2);
	else 
	{
		double A=1-pow(q,k1-1),B=1-pow(p,k2-1);
		double C=A/p,D=B/q;
		double F=(A*D+C)/(1-A*B);
		double G=(B*C+D)/(1-A*B);
		printf("%.7f\n",G*p+F*q+1);
	}
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}
