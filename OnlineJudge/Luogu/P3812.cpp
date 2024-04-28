#include<bits/stdc++.h>
using namespace std;
typedef long long ago;
const int N=65;
ago A[N],x,ans;int n;
void Insert(ago x)
{
	for(int i=60;~i;--i)
	{
		if(!(1ll<<i&x))continue;
		if(A[i])x^=A[i];
		else
		{
			for(int j=0;j<i;++j)if(1ll<<j&x)x^=A[j];
			for(int j=i+1;j<=60;++j)if(1ll<<i&A[j])A[j]^=x;
			A[i]=x;return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&x),Insert(x);
	for(int i=0;i<=60;++i)ans^=A[i];
	printf("%lld\n",ans);
}