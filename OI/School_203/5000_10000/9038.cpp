//题面(l,r]就很灵魂,其实是[l,r]
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int nowAns,S,n,m,A[N],cnt[N<<2],ans[N],l=1,r;
struct Que
{
	int id,pl,l,r;
	void read(int i)
	{
		scanf("%d%d",&l,&r);
		pl=l/S;id=i;
	}
	bool operator <(const Que &_)const
	{
		return pl==_.pl?(pl&1?r<_.r:r>_.r):pl<_.pl;//网上看到的奇怪的奇偶优化
	}
}Q[N];
int main()
{
	scanf("%d%d",&n,&m);S=sqrt(n)+1;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),A[i]^=A[i-1];
	for(int i=1;i<=m;++i)Q[i].read(i);sort(Q+1,Q+m+1);
	for(int i=1;i<=m;++i)
	{
		int ll=Q[i].l,rr=Q[i].r;
		while(l>ll)nowAns+=cnt[A[--l]]++;
		while(l<ll)nowAns-=--cnt[A[l++]];
		while(r<rr)nowAns+=cnt[A[++r]]++;
		while(r>rr)nowAns-=--cnt[A[r--]];
		ans[Q[i].id]=nowAns;
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
}