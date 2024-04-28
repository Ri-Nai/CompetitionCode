#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,Q,A[N];
int rd()
{
	int t=0,c;do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
int main()
{
	n=rd();Q=rd();
	for(int i=1,k,m;i<=Q;++i)
	{
		k=rd();bool flag=0;
		for(int j=1;j<=k;++j)
			A[j]=rd();m=rd();
		for(int j=1;!flag&&j<=k;++j)
			if(A[j]==m)flag=1;
		if(flag)printf("%.7f\n",0.5*(n+k));
		else printf("%.7f\n",1.0*n+k);
	}
}