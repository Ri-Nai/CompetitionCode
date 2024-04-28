#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=1<<16;
int W,n,A[20],B[20],w[maxn+5],t[maxn+5],bit[maxn+5],M;
void in_put()
{
	scanf("%d%d",&W,&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&A[i],&B[i]);
	M=1<<n;
}
void solve()
{
	for(int i=1;i<=16;++i)bit[1<<i]=i;
	for(int i=1;i<M;++i)
	{
		int last=i&(-i);
		w[i]=w[i^last]+B[bit[last]+1];
		t[i]=std::max(t[i^last],A[bit[last]+1]);
		if(w[i]>W)t[i]=0x3f3f3f3f;
	}
	for(int i=0;i<M;++i)
		for(int j=i;j;j=(j-1)&i)
			t[i]=std::min(t[i],t[i^j]+t[j]);
	printf("%d\n",t[M-1]);
}
int main()
{
	in_put();
	solve();	
}