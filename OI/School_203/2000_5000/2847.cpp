#include<cstdio>
#define ls p<<1
#define rs p<<1|1
#define mid ((tree[p].l+tree[p].r)>>1)
#define int long long
const int maxn=1e5+5,mod=1e9+7;
struct ${int l,r,ssum,dsum,len,add;}tree[maxn<<2];
int n,m,A[maxn];
void build(int l,int r,int p)
{
	if(l==r)tree[p]=($){l,r,A[l]*A[l],A[l],r-l+1,0};
	else
	{
		tree[p].l=l,tree[p].r=r;
		build(l,mid,ls),build(mid+1,r,rs);
		tree[p]=($){l,r,(tree[ls].ssum+tree[rs].ssum)%mod,
		(tree[ls].dsum+tree[rs].dsum)%mod,r-l+1,0};
	}
}
void updnode(int p,int x)
{
	(tree[p].add+=x)%=mod;
	(tree[p].ssum+=2*x*tree[p].dsum+tree[p].len*x%mod*x)%=mod;
	(tree[p].dsum+=x*tree[p].len)%mod;
}
void Down(int p)
{
	int &x=tree[p].add;
	if(x==0)return	;
	updnode(ls,x),updnode(rs,x);
	x=0;
}
void update(int l,int r,int x,int p)
{
	if(tree[p].l==l&&tree[p].r==r)
		updnode(p,x);
	else
	{
		Down(p);
		if(r<=mid)update(l,r,x,ls);
		else if(l>mid)update(l,r,x,rs);
		else update(l,mid,x,ls),update(mid+1,r,x,rs);
		(tree[p].dsum=tree[ls].dsum+tree[rs].dsum)%=mod;
		(tree[p].ssum=tree[ls].ssum+tree[rs].ssum)%=mod;

	}
}
int query(int l,int r,int p)
{
	if(l==tree[p].l&&r==tree[p].r)
		return tree[p].ssum;
	Down(p);
	if(r<=mid)return query(l,r,ls);
	else if(l>mid)return query(l,r,rs);
	else return (query(l,mid,ls)+query(mid+1,r,rs))%mod;
}
main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&A[i]);
	build(1,n,1);
	int l,r,x;char tmp[3];
	while(m--)
	{
		scanf("%s%lld%lld",tmp,&l,&r);
		if(tmp[0]=='Q')printf("%lld\n",query(l,r,1));
		else scanf("%lld",&x),update(l,r,x,1);
	}
}