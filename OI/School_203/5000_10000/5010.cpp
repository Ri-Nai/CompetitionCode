#include<bits/stdc++.h>
const int N=5e4+5;
using namespace std;
typedef long long LL;
int Q[N],L=1,R=1,n,l;
LL A[N],X[N],Y[N],dp[N],Sum[N];
double K(int a,int b)
{
	return 1.0*(Y[a]-Y[b])/(X[a]-X[b]);
}
int main()
{
	cin>>n>>l;X[0]=l+1;
	Y[0]=X[0]*X[0];
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&Sum[i]);
		Sum[i]+=Sum[i-1];
		A[i]=Sum[i]+i;
		X[i]=Sum[i]+i+l+1;
	}
	for(int i=1;i<=n;++i)
	{
		while(L<R&&K(Q[L],Q[L+1])<2*A[i])++L;
		int p=Q[L];
		dp[i]=dp[p]+(A[i]-X[p])*(A[i]-X[p]);
		Y[i]=dp[i]+X[i]*X[i];
		while(L<R&&K(i,Q[R-1])<K(Q[R-1],Q[R]))--R;
		Q[++R]=i;
	}
	printf("%lld\n",dp[n]);
}
