#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=1e5+5;
int A[maxn],n,m,Rsm[maxn];
struct Prefessional_Team
{
	struct node
	{
		int L,R,mx,mn,Lsum,Rsum,valsum,sum;
	}T[maxn<<2];
	void Up(int p)
	{
		if(T[ls].mx>T[rs].mx)T[p].Lsum=T[ls].Lsum;
		else T[p].Lsum=T[rs].Lsum;
		T[p].mx=max(T[ls].mx,T[rs].mx);
		T[p].mn=min(T[ls].mn,T[rs].mn);

		T[p].sum=max(T[ls].sum,T[rs].sum);
		T[p].sum=max(T[p].sum,T[ls].Rsum+T[rs].Lsum);
		
		T[p].Lsum=max(T[ls].Lsum,T[ls].valsum+T[rs].Lsum);
		T[p].Rsum=max(T[rs].Rsum,T[rs].valsum+T[ls].Rsum);

		T[p].valsum=T[ls].valsum+T[rs].valsum;
	}
	void build(int L,int R,int p)
	{
		T[p].L=L,T[p].R=R;
		if(L==R)
		{
			T[p].mx=Rsm[L]+A[L];T[p].mn=Rsm[L];
			T[p].sum=T[p].valsum=T[p].Lsum=T[p].Rsum=A[L];
			return;
		}
		int mid=L+R>>1;
		build(L,mid,ls);
		build(mid+1,R,rs);
		Up(p);
	}
	int query_max(int L,int R,int p)
	{
		if(L<=T[p].L&&T[p].R<=R)return T[p].mx;
		int mid=T[p].L+T[p].R>>1;
		if(R<=mid)return query_max(L,R,ls);
		else if(L>mid)return query_max(L,R,rs);
		return max(query_max(L,R,ls),query_max(L,R,rs));
	}
	int query_min(int L,int R,int p)
	{
		if(L<=T[p].L&&T[p].R<=R)return T[p].mn;
		int mid=T[p].L+T[p].R>>1;
		if(R<=mid)return query_min(L,R,ls);
		else if(L>mid)return query_min(L,R,rs);
		return min(query_min(L,R,ls),query_min(L,R,rs));
	}
	node Get(node a,node b)
	{
		node res;
		res.sum=max(a.Rsum+b.Lsum,max(a.sum,b.sum));
		res.valsum=a.valsum+b.valsum;
		res.Lsum=max(a.Lsum,a.valsum+b.Lsum);
		res.Rsum=max(b.Rsum,b.valsum+a.Rsum);
		return res;
	}
	node query(int L,int R,int p)
	{
		if(L<=T[p].L&&T[p].R<=R)return T[p];
		int mid=T[p].L+T[p].R>>1;
		if(L>mid)return query(L,R,rs);
		else if(R<=mid)return query(L,R,ls);
		return Get(query(L,R,ls),query(L,R,rs));
	}
}Team;
int Getans(int l1,int r1,int l2,int r2)
{
	if(r1<=l2)return Team.query_max(l1,r1,1)-Team.query_min(l2,r2,1);
	int a=Team.query(l2,r1,1).sum;
	int b=Team.query_max(l1,l2,1)-Team.query_min(l2,r2,1);
	int c=Team.query_max(l1,r1,1)-Team.query_min(r1,r2,1);
	return max(a,max(b,c));
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(Rsm,0,sizeof Rsm);
		for(int i=1;i<=n;++i)scanf("%d",&A[i]);
		for(int i=n-1;i;--i)Rsm[i]=Rsm[i+1]+A[i+1];
		Team.build(1,n,1);scanf("%d",&m);
		for(int i=1,x1,x2,y1,y2;i<=m;++i)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",Getans(x1,y1,x2,y2));
		}
	}
}