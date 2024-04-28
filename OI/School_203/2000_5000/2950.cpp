#include<cstdio>
#include<cstring>
#include<algorithm>
#define ls (p<<1)
#define rs (p<<1|1)
const int maxn=2e5+5;
struct Seg
{
    int l,r,mx;
}tree[maxn<<2];
int A[maxn],B[maxn],n,m,ans,len;
int build(int l,int r,int p)
{
    tree[p].l=l;tree[p].r=r;
    if(l==r)return tree[p].mx=0;
    int mid=l+r>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
}
int query(int l,int r,int p)
{
    if(tree[p].l==l&&tree[p].r==r)return tree[p].mx;
    int mid=tree[p].l+tree[p].r>>1;
    if(r<=mid)return query(l,r,ls);
    else if(l>mid)return query(l,r,rs);
    else return std::max(query(l,mid,ls),query(mid+1,r,rs));
}
int update(int x,int a,int p)
{
    if(tree[p].l==tree[p].r)return tree[p].mx=a;
    int mid=tree[p].l+tree[p].r>>1;
    if(x<=mid)update(x,a,ls);
    else update(x,a,rs);
    tree[p].mx=std::max(tree[ls].mx,tree[rs].mx);
}
int main()
{
	scanf("%d%d",&n,&m);ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	std::sort(B+1,B+n+1);len=std::unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)
	{
		int now=std::lower_bound(B+1,B+len+1,A[i])-B,
			l=std::lower_bound(B+1,B+len+1,A[i]-m)-B,
			r=std::upper_bound(B+1,B+len+1,A[i]+m)-B-1;
		int tmp=query(l,r,1);
		update(now,tmp+1,1);ans=std::max(tmp+1,ans);
	}
	printf("%d\n",ans);
}