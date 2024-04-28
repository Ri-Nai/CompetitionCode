#include<cstdio>
#include<algorithm>
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
const int maxn=2e5+5;
int n,m,A[maxn];char tmp[2];
struct Seg
{
	int mx[maxn<<2];
	int build(int L,int R,int p)
	{
		if(L==R)return mx[p]=A[L];
		return mx[p]=std::max(build(L,mid,ls),build(mid+1,R,rs));
	}
	void updata(int L,int R,int x,int a,int p)
	{
		if(L==R){mx[p]=a;return;}
		if(x<=mid)updata(L,mid,x,a,ls);
		else updata(mid+1,R,x,a,rs);
		mx[p]=std::max(mx[ls],mx[rs]);
	}
	int query(int L,int R,int l,int r,int p)
	{
		if(l==L&&R==r)return mx[p];
		if(r<=mid)return query(L,mid,l,r,ls);
		else if(l>mid)return query(mid+1,R,l,r,rs);
		return std::max(query(L,mid,l,mid,ls),query(mid+1,R,mid+1,r,rs));
	}
}Tree;
void solve()
{
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	Tree.build(1,n,1);
	while(m--)
	{
		int x,y;
		scanf("%s%d%d",tmp,&x,&y);
		if(tmp[0]=='U')Tree.updata(1,n,x,y,1);
		else printf("%d\n",Tree.query(1,n,x,y,1));
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))solve();
}