#include<cstdio>
#include<algorithm>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=5e4+5;
struct Prefessional_Team
{
	int mn[maxn<<2];
	void bulid(int L,int R,int p)
	{
		if(L==R)
		{
			if(L==1)mn[p]=0;
			else mn[p]=0x3f3f3f3f;
			return;
		}
		int mid=L+R>>1;
		bulid(L,mid,ls);
		bulid(mid+1,R,rs);
		mn[p]=min(mn[ls],mn[rs]);
	}
	void updata(int L,int R,int x,int a,int p)
	{
		if(L==R){mn[p]=a;return;}
		int mid=L+R>>1;
		if(x<=mid)updata(L,mid,x,a,ls);
		else updata(mid+1,R,x,a,rs);
		mn[p]=min(mn[ls],mn[rs]);
	}
	int query(int L,int R,int l,int r,int p)
	{
		if(L==l&&R==r)return mn[p];
		int mid=L+R>>1;
		if(r<=mid)return query(L,mid,l,r,ls);
		else if(l>mid)return query(mid+1,R,l,r,rs);
		else return min(query(L,mid,l,mid,ls),query(mid+1,R,mid+1,r,rs));
	}
}T;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	T.bulid(1,n,1);
	for(int i=1,l,r;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		int mn=min(T.query(1,n,l,r,1)+1,T.query(1,n,r,r,1));
		T.updata(1,n,r,mn,1);
	}
	printf("%d\n",T.query(1,n,n,n,1));
}