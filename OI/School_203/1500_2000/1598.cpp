#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=86400;
long long sum[N],diff[N];
int n,Q;
int read()
{
	int hh,mm,ss;
	scanf("%d:%d:%d",&hh,&mm,&ss);
	return hh*3600+mm*60+ss;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int B=read();
		scanf(" - ");
		int E=read();
		if(E<B)++diff[0],++diff[B],--diff[E+1];
		else ++diff[B],--diff[E+1];
	}
	sum[0]=diff[0];
	long long now=diff[0];
	for(int i=1;i<=M;++i)
	{
		now+=diff[i];
		sum[i]=now+sum[i-1];
	}
	for(scanf("%d",&Q);Q--;)
	{
		int B=read();
		scanf(" - ");
		int E=read();
		if(B<=E)printf("%.10f\n",1.0*(sum[E]-(B?sum[B-1]:0))/(E-B+1));
		else printf("%.10f\n",1.0*(sum[M-1]+sum[E]-(B?sum[B-1]:0))/(E+M-B+1));
	}
}