#include<cstdio>
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
#define LL long long
const int maxn=5e4+5;
int A[maxn],n;
struct Seg
{
	LL Sum[maxn<<2];
	LL build(int L,int R,int p)
	{
		if(L==R)return Sum[p]=A[L];
		return Sum[p]=build(L,mid,ls)+build(mid+1,R,rs);
	}
	void Renew(int L,int R,int x,int a,int p)
	{
		if(L==R){Sum[p]+=a;return;}
		if(x<=mid)Renew(L,mid,x,a,ls);
		else Renew(mid+1,R,x,a,rs);
		Sum[p]=Sum[ls]+Sum[rs];
	}
	LL query(int L,int R,int l,int r,int p)
	{
		if(L==l&&r==R)return Sum[p];
		if(r<=mid)return query(L,mid,l,r,ls);
		else if(l>mid)return query(mid+1,R,l,r,rs);
		else return query(L,mid,l,mid,ls)+query(mid+1,R,mid+1,r,rs);
	}
}Tree;
void solve(int id)
{
	printf("Case %d:\n",id);
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&A[i]);
	Tree.build(1,n,1);
	while(1)
	{
		char tmp[6];scanf("%s",tmp);
		if(tmp[0]=='E')break;
		int i,j;scanf("%d%d",&i,&j);
		if(tmp[0]=='A')Tree.Renew(1,n,i,j,1);
		if(tmp[0]=='S')Tree.Renew(1,n,i,-j,1);
		if(tmp[0]=='Q')printf("%lld\n",Tree.query(1,n,i,j,1));
	}

}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}