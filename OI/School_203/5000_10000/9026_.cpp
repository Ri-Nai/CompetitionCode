#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+5,M=1e4+5;
struct Climb
{
	int l,r;
	bool operator < (const Climb &_)const{return r<_.r;}
	void read(){scanf("%d%d",&l,&r);if((l+=M)>(r+=M))swap(l,r);}
}A[N];
bool mark[M<<2];
int n,K,ans[M<<2],tot;
int main()
{
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;++i)A[i].read();
	sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
	{
		int now=min(A[i].r-A[i].l+1,K);
		for(int j=A[i].r;j>=A[i].l;--j)now-=mark[j];
		for(int j=A[i].r;now>0;--j)
			if(!mark[j])now-=mark[ans[++tot]=j]=1;
	}sort(ans+1,ans+tot+1);printf("%d\n",tot);
	for(int i=1;i<=tot;++i)printf("%d\n",ans[i]-M);
}