#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int A[maxn],n,m;
struct Seg
{
#define ls p<<1
#define rs p<<1|1
	int Lsum[maxn<<2],Rsum[maxn<<2],sum[maxn<<2];
	void Up(int L,int R,int p)
	{
		int mid=L+R>>1;
		sum[p]=max(sum[ls],sum[rs]);
		Lsum[p]=Lsum[ls];Rsum[p]=Rsum[rs];
		if(A[mid]<A[mid+1])
		{
			if(Lsum[ls]==mid-L+1)Lsum[p]+=Lsum[rs];
			if(Rsum[rs]==R-mid)Rsum[p]+=Rsum[ls];
			sum[p]=max(sum[p],Rsum[ls]+Lsum[rs]);
		}
	}
	void build(int L,int R,int p)
	{
		if(L==R)
		{
			sum[p]=Lsum[p]=Rsum[p]=1;
			return ;
		}
		int mid=L+R>>1;
		build(L,mid,ls);
		build(mid+1,R,rs);
		Up(L,R,p);
	}
	void updata(int L,int R,int x,int a,int p)
	{
		if(L==R){A[L]=a;return;}
		int mid=L+R>>1;
		if(x<=mid)updata(L,mid,x,a,ls);
		else updata(mid+1,R,x,a,rs);
		Up(L,R,p);
		//printf("`````%d %d\n",p,sum[p]);
	}
	int qurey(int L,int R,int l,int r,int p)
	{
		if(l<=L&&r>=R)return sum[p];
		int mid=L+R>>1,res=0;
		if(l<=mid)res=max(res,qurey(L,mid,l,r,ls));
		if(r>mid)res=max(res,qurey(mid+1,R,l,r,rs));
		if(A[mid]<A[mid+1])
			res=max(res,min(mid-l+1,Rsum[ls])+min(r-mid,Lsum[rs]));
		//printf("`````%d %d %d %d %d %d\n",res,L,R,l,r,p);
		return res;
	}
#undef ls
#undef rs
}Tree;
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	Tree.build(1,n,1);
	while(m--)
	{
		char tmp[2];int a,b;
		scanf("%s%d%d",tmp,&a,&b);
		if(tmp[0]=='Q')printf("%d\n",Tree.qurey(1,n,a+1,b+1,1));
		else Tree.updata(1,n,a+1,b,1);
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}