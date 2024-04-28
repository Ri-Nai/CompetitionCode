#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5;
int A[maxn],n,m,mod;
struct Seg
{
	#define ls p<<1
	#define rs p<<1|1
	#define mid (Tree[p].L+Tree[p].R>>1)
	struct node
	{
		int L,R,len;
		LL sum,Tm,Ad;
	}Tree[maxn<<2];
	void change(int p,LL Time,LL Add)
	{
		if(Time==1&&Add==0)return;
		LL &Tm=Tree[p].Tm,&Ad=Tree[p].Ad,&sum=Tree[p].sum;
		Tm=(Time*Tm)%mod;
		Ad=(Ad*Time+Add)%mod;
		sum=(sum*Time+Add*Tree[p].len)%mod;
	}
	void Up(int p)
	{
		Tree[p].sum=(Tree[ls].sum+Tree[rs].sum)%mod;
	}
	void down(int p)
	{
		change(ls,Tree[p].Tm,Tree[p].Ad);
		change(rs,Tree[p].Tm,Tree[p].Ad);
		Tree[p].Tm=1;Tree[p].Ad=0;
	}
	void build(int L,int R,int p)
	{
		Tree[p].Tm=1;Tree[p].Ad=0;
		Tree[p].L=L;Tree[p].R=R;
		Tree[p].len=R-L+1;
		if(L==R)
		{
			Tree[p].sum=A[L]%mod;
			return ;
		}
		build(L,mid,ls);
		build(mid+1,R,rs);
		Up(p);
	}
	void update(int L,int R,int k,int c,int p)
	{
		if(L==Tree[p].L&&R==Tree[p].R)
		{
			if(k==1)change(p,c,0);
			else change(p,1,c);
			return;
		}
		down(p);
		if(R<=mid)update(L,R,k,c,ls);
		else if(L>mid)update(L,R,k,c,rs);
		else update(L,mid,k,c,ls),update(mid+1,R,k,c,rs);
		Up(p);
	}
	LL query(int L,int R,int p)
	{
		if(L==Tree[p].L&&R==Tree[p].R)
			return Tree[p].sum;
		down(p);
		if(R<=mid)return query(L,R,ls);
		if(L>mid)return query(L,R,rs);
		return (query(L,mid,ls)+query(mid+1,R,rs))%mod;
	}
}T;
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	T.build(1,n,1);scanf("%d",&m);
	while(m--)
	{
		int flag,L,R,c;
		scanf("%d%d%d",&flag,&L,&R);
		if(flag!=3)scanf("%d",&c),T.update(L,R,flag,c,1);
		else printf("%lld\n",T.query(L,R,1));
	}
}