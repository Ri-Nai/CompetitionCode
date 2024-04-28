#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=5e4+5;
#define ls p<<1
#define rs p<<1|1
int n,A[maxn],Mx,Pos;
struct Seg
{
	int mx[maxn<<2],mn[maxn<<2],pos[maxn<<2];
	void Up(int p)
	{
		if(mx[ls]>=mx[rs])mx[p]=mx[ls],pos[p]=pos[ls];
		else mx[p]=mx[rs],pos[p]=pos[rs];
		mn[p]=min(mn[ls],mn[rs]);
	}
	void bulid(int L,int R,int p)
	{
		if(L==R){mn[p]=mx[p]=A[L];pos[p]=L;return;}
		int mid=L+R>>1;
		bulid(L,mid,ls);
		bulid(mid+1,R,rs);
		Up(p);
	}
	int query_min(int L,int R,int l,int r,int p)
	{
		if(L==l&&R==r)return mn[p];
		int mid=L+R>>1;
		if(r<=mid)return query_min(L,mid,l,r,ls);
		else if(l>mid)return query_min(mid+1,R,l,r,rs);
		return min(query_min(L,mid,l,mid,ls),query_min(mid+1,R,mid+1,r,rs));
	}
	void query_max(int L,int R,int l,int r,int p)
	{
		if(L==l&&R==r)
		{
			if(mx[p]>Mx)Mx=mx[p],Pos=pos[p];
			return ;
		}
		int mid=L+R>>1;
		if(r<=mid)query_max(L,mid,l,r,ls);
		else if(l>mid)query_max(mid+1,R,l,r,rs);
		else query_max(L,mid,l,mid,ls),query_max(mid+1,R,mid+1,r,rs);
	}
}Tree;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)scanf("%d",&A[i]);
		int ans=-1;Tree.bulid(1,n,1);
		for(int i=1;i<=n;++i)
		{
			int l=i+1,r=n,res=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(mid-i<=ans){l=mid+1;continue;}
				int tmp=Tree.query_min(1,n,i+1,mid,1);
				if(tmp<=A[i])r=mid-1;
				else l=mid+1,res=mid;
			}
			if(res-i>ans)
			{
				Mx=A[i],Pos=i;
				Tree.query_max(1,n,i+1,res,1);
				if(Mx>A[i]&&Pos-i>ans)ans=Pos-i;
			}
		}
		printf("%d\n",ans);
	}
}
