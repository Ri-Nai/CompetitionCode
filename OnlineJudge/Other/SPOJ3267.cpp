#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e4+5,M=1e6+5,QQ=2e5+5;
int S,n,m,cnt[M],A[N],ans[QQ],l=1,r,nowAns;
struct Que
{
	int bl,l,r,id;
	void read(int i)
	{
		scanf("%d%d",&l,&r);
		id=i;bl=l/S;
	}
	bool operator <(const Que &_)const
	{
		return bl==_.bl?(bl&1?(r<_.r):(r>_.r)):bl<_.bl;
	}
}Q[QQ];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&A[i]);S=sqrt(n)+1;
	scanf("%d",&m);for(int i=1;i<=m;++i)Q[i].read(i);sort(Q+1,Q+m+1);
	for(int i=1;i<=m;++i)
	{
		int ll=Q[i].l,rr=Q[i].r;
		while(l>ll)nowAns+=!cnt[A[--l]]++;
		while(l<ll)nowAns-=!--cnt[A[l++]];
		while(r<rr)nowAns+=!cnt[A[++r]]++;
		while(r>rr)nowAns-=!--cnt[A[r--]];
		ans[Q[i].id]=nowAns;
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
}