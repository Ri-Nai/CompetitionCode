#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Y(x) (Sum[x-1])
const int N=3e5+5;
int n,A[N],Q[N],R;
LL Sum[N];
inline LL Get(int p,int k)
{
	return -1ll*p*k+Y(p);
}
bool chk(int a,int b,int c)
{
	return (Y(a)-Y(b))*(c-b)>(Y(b)-Y(c))*(b-a);
}
LL Get(int k)
{
	int l=2,r=R,res=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(Get(Q[mid],k)>Get(Q[mid-1],k))
			l=mid+1,res=mid;
		else r=mid-1;
	}
	return Get(Q[res],k);
}
void Solve()
{
	for(int i=1;i<=n;++i)Sum[i]=Sum[i-1]+A[i];
	LL ans=-1e18;R=0;
	for(int i=1;i<=n;++i)
	{
		if(R)ans=max(ans,Get(A[i])+1ll*A[i]*(i+1)+Sum[n]-Sum[i]);
		while(R>1&&chk(Q[R-1],Q[R],i))--R;Q[++R]=i;
	}
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	Solve();reverse(A+1,A+n+1);Solve();
}