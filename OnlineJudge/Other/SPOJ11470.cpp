#include<bits/stdc++.h>
#define mid (L+R>>1)
#define LL long long
using namespace std;
const int maxn=1e5+5,maxm=8e6+5;
int n,m,T;
int tot,RT[maxn],ls[maxm],rs[maxm];
LL sum[maxm],lazy[maxm],A[maxn];//prefessional team
void build(int L,int R,int &rt)
{
	rt=++tot;if(L==R){sum[rt]=A[L];return ;}
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
	sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
void updata(int L,int R,int l,int r,int x,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot];lazy[rt]=lazy[ot];
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==l&&r==R){lazy[rt]+=x;return;}
	if(r<=mid)updata(L,mid,l,r,x,ls[ot],ls[rt]);
	else if(l>mid)updata(mid+1,R,l,r,x,rs[ot],rs[rt]);
	else updata(L,mid,l,mid,x,ls[ot],ls[rt]),updata(mid+1,R,mid+1,r,x,rs[ot],rs[rt]);
	sum[rt]=sum[ls[rt]]+sum[rs[rt]]+lazy[ls[rt]]*(mid-L+1)+lazy[rs[rt]]*(R-mid);
}
LL query(int L,int R,int l,int r,int rt)
{
	if(L==l&&r==R)return sum[rt]+lazy[rt]*(r-l+1);
	LL v=lazy[rt]*(r-l+1);
	if(r<=mid)return query(L,mid,l,r,ls[rt])+v;
	if(l>mid)return query(mid+1,R,l,r,rs[rt])+v;
	return query(L,mid,l,mid,ls[rt])+query(mid+1,R,mid+1,r,rs[rt])+v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&A[i]);
	build(1,n,RT[0]);
	while(m--)
	{
		int l,r,x;
		char tmp[2];scanf("%s",tmp);
		if(tmp[0]=='B')
			scanf("%d",&T);
		if(tmp[0]=='C')
			scanf("%d%d%d",&l,&r,&x),
			++T,updata(1,n,l,r,x,RT[T-1],RT[T]);
		if(tmp[0]=='Q')
			scanf("%d%d",&l,&r),
			printf("%lld\n",query(1,n,l,r,RT[T]));
		if(tmp[0]=='H')
			scanf("%d%d%d",&l,&r,&x),
			printf("%lld\n",query(1,n,l,r,RT[x]));
	}
}