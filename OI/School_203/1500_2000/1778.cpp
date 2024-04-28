#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,len,C[N],P;
long long A[N],B[N],ans;
void Add(int x)
{
	while(x<=len)++C[x],x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&A[i]);
	scanf("%d",&P);
	for(int i=1;i<=n;++i)
	{
		A[i]-=P;
		A[i]+=A[i-1];
		B[i]=A[i];
	}
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B;
	for(int i=1;i<=n;++i)
	{
		ans+=Sum(A[i]);Add(A[i]);
		if(B[A[i]]>=0)++ans;
	}
	printf("%lld\n",ans);
}