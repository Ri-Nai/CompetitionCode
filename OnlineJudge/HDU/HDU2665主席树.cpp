#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=2e6+5;
#define mid (L+R>>1)
int ls[maxm],rs[maxm],cnt[maxm],
tree[maxn],A[maxn],B[maxn],tot,n,m,len;
void build(int L,int R,int &rt)
{
	cnt[rt]=0;rt=++tot;if(L==R)return ;
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
}
void Insret(int L,int R,int x,int ot,int &rt)
{
	rt=++tot;cnt[rt]=cnt[ot]+1;
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==R)return;
	if(x<=mid)Insret(L,mid,x,ls[ot],ls[rt]);
	else Insret(mid+1,R,x,rs[ot],rs[rt]);
}
int query(int L,int R,int lt,int rt,int k)
{
	if(L==R)return R;
	int now=cnt[ls[rt]]-cnt[ls[lt]];
	if(k<=now)return query(L,mid,ls[lt],ls[rt],k);
	else return query(mid+1,R,rs[lt],rs[rt],k-now);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
		sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
		build(1,len,tree[0]);
		for(int i=1;i<=n;++i)
			A[i]=lower_bound(B+1,B+len+1,A[i])-B,
			Insret(1,len,A[i],tree[i-1],tree[i]);
		while(m--)
		{
			int L,R,k;
			scanf("%d%d%d",&L,&R,&k);
			printf("%d\n",B[query(1,len,tree[L-1],tree[R],k)]);
		}
	}
}