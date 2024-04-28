#include<cstdio>
#include<cstring>
#define LL long long
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
const int maxn=1e5+5;
int n,m,A[maxn];
struct Seg
{
	LL sum[maxn<<2],Add[maxn<<2];
	Seg(){memset(sum,0,sizeof sum),memset(Add,0,sizeof Add);}
	LL build(int L,int R,int p)
	{
		if(L==R)return sum[p]=A[L];
		return sum[p]=build(L,mid,ls)+build(mid+1,R,rs);
	}
	void down(int p,int L,int R)
	{
		LL &t=Add[p];
		if(!t)return;
		Add[ls]+=t;Add[rs]+=t;
		sum[ls]+=t*(mid-L+1);
		sum[rs]+=t*(R-mid);
		t=0;
	}
	void updata(int L,int R,int l,int r,int a,int p)
	{
		if(L==l&&r==R){Add[p]+=a;sum[p]+=(R-L+1)*a;return;}
		down(p,L,R);
		if(r<=mid)updata(L,mid,l,r,a,ls);
		else if(l>mid)updata(mid+1,R,l,r,a,rs);
		else updata(L,mid,l,mid,a,ls),updata(mid+1,R,mid+1,r,a,rs);
		sum[p]=sum[ls]+sum[rs];
	}
	LL qurey(int L,int R,int l,int r,int p)
	{
		if(L==l&&R==r)return sum[p];
		down(p,L,R);
		if(r<=mid)return qurey(L,mid,l,r,ls);
		else if(l>mid)return qurey(mid+1,R,l,r,rs);
		else return qurey(L,mid,l,mid,ls)+qurey(mid+1,R,mid+1,r,rs);
	}
}Tree;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	Tree.build(1,n,1);
	while(m--)
	{
		int x,y,z;char tmp[2];
		scanf("%s%d%d",&tmp,&x,&y);
		if(tmp[0]=='Q')printf("%lld\n",Tree.qurey(1,n,x,y,1));
		else scanf("%d",&z),Tree.updata(1,n,x,y,z,1);
	}
}