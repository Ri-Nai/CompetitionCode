#include<bits/stdc++.h>
using namespace std;
typedef long long ago;
const int M=62;
ago A[M+2],B[M+2],x;int n,Q,cnt;
void Insert(ago x)
{
	for(int i=M;~i;--i)
	{
		if(!(1ll<<i&x))continue;
		if(A[i])x^=A[i];
		else
		{
			for(int j=0;j<i;++j)if(1ll<<j&x)x^=A[j];
			for(int j=i+1;j<=M;++j)if(1ll<<i&A[j])A[j]^=x;
			A[i]=x;return;
		}
	}
}
ago Query(ago k)
{
	if(cnt!=n)--k;
	if(k>=1ll<<cnt)return -1ll;
	ago ans=0;
	for(int i=0;i<cnt;++i)
		if(1ll<<i&k)ans^=B[i];
	return ans;
}
void solve(int Cas)
{
	scanf("%d",&n);cnt=0;
	memset(A,0,sizeof A);
	for(int i=1;i<=n;++i)scanf("%lld",&x),Insert(x);
	for(int i=0;i<=M;++i)if(A[i])B[cnt++]=A[i];
	scanf("%d",&Q);printf("Case #%d:\n",Cas);
	for(ago k;Q--;)scanf("%lld",&k),printf("%lld\n",Query(k));

}
int main()
{
	int T;cin>>T;
	for(int i=1;i<=T;++i)solve(i);
}