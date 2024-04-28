#include<bits/stdc++.h>
using namespace std;
const int N=1005;
double k1=0,k2=1e18;
int n,A[N],B[N];long long sum;
void Compare(int a1,int a2,int b1,int b2)
{
	if(a1<a2&&b1<=b2)puts("-1"),exit(0);
	int d1=a2-a1,d2=b1-b2;
	if(!d2&&d1>0)puts("-1"),exit(0);
	if(!d2)return ;
	if(d2<0)k2=min(k2,1.0*d1/d2);
	else k1=max(k1,1.0*d1/d2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&A[i],&B[i]),sum+=B[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			Compare(A[i],A[j],B[i],B[j]);
	if(k1>k2)puts("-1");
	else if(k2==1e18)puts("-1");
	else if(k1<0||k2<0)puts("-1");
	else printf("%.6f\n",(k1+k2)/2*sum);
}