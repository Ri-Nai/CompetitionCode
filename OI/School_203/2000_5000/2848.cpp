#include<cstdio>
#include<algorithm>
#define ls p<<1
#define rs p<<1|1
#define mid ((tree[p].l+tree[p].r)>>1)
#define int long long
const int maxn=1e6+5,mod=1e9+7;
struct ${int l,r,ssum,dsum,len,add;}tree[maxn<<2];
int n,m,pre[maxn];
void build(int l,int r,int p)
{
	tree[p].l=l;tree[p].r=r;
	if(l==r)return ;
	build(l,mid,ls),build(mid+1,r,rs);
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
struct point 
{
    int x,id;
    bool operator <(const point &a)const {
        if(x!=a.x)return x<a.x;
        return id<a.id;
    }
}P[maxn];
main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&P[i].x),P[i].id=i;
    std::sort(P+1,P+1+n);
	build(1,n,1);
	 for(int i=2;i<=n;i++)
        if(P[i].x==P[i-1].x)pre[P[i].id]=P[i-1].id;
    int ans=0;
    for(int i=1;i<=n;i++){
        update(pre[i]+1,i,1,1);
        (ans+=tree[1].ssum)%=mod; 
    }
    printf("%lld\n",ans);
}