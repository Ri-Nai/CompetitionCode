#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int n,q,B[maxn],len;
struct _
{
	int v,id;
	bool operator < (_ __)const
	{
		return v<__.v;
	}
}A[maxn];
struct node
{
	int sum,Lsum,Rsum;
	node(){sum=Lsum=Rsum=0;}
	node(int _){sum=Lsum=Rsum=_;}
}Tree[maxn<<5];
int ls[maxn<<5],rs[maxn<<5],RT[maxn],tot;
#define mid (L+R>>1)
node Up(node L,node R)
{
	node now;
	now.sum=L.sum+R.sum;
	now.Lsum=max(L.Lsum,L.sum+R.Lsum);
	now.Rsum=max(R.Rsum,R.sum+L.Rsum);
	return now;
}
void build(int L,int R,int &rt)
{
	rt=++tot;if(L==R){Tree[rt]=node(1);return ;}
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
	Tree[rt]=Up(Tree[ls[rt]],Tree[rs[rt]]);
}
void updata(int L,int R,int x,int ot,int &rt)
{
	rt=++tot;
	ls[rt]=ls[ot];
	rs[rt]=rs[ot];
	if(L==R)
	{
		Tree[rt]=node(-1);
		return;
	}
	if(x<=mid)updata(L,mid,x,ls[ot],ls[rt]);
	else updata(mid+1,R,x,rs[ot],rs[rt]);
	Tree[rt]=Up(Tree[ls[rt]],Tree[rs[rt]]);
}
node query(int L,int R,int l,int r,int rt)
{
	if(l>r)return node();
	if(L==l&&R==r)return Tree[rt];
	if(r<=mid)return query(L,mid,l,r,ls[rt]);
	if(l>mid)return query(mid+1,R,l,r,rs[rt]);
	return Up(query(L,mid,l,mid,ls[rt]),query(mid+1,R,mid+1,r,rs[rt]));
}
#undef mid
bool check(int a,int b,int c,int d,int k)
{
	return query(1,n,b+1,c-1,RT[k]).sum+query(1,n,a,b,RT[k]).Rsum+query(1,n,c,d,RT[k]).Lsum>=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&B[i]),A[i].v=B[i],A[i].id=i;
	sort(B+1,B+n+1);len=unique(B+1,B+1+n)-B-1;sort(A+1,A+n+1);
	build(1,n,RT[1]);int now=1;
	for(int i=2;i<=len;++i)
	{
		RT[i]=RT[i-1];
		while(A[now].v==B[i-1])updata(1,n,A[now++].id,RT[i],RT[i]);
	}
	scanf("%d",&q);now=0;
	while(q--)
	{
		int x[6];
		for(int i=1;i<=4;++i)scanf("%d",&x[i]),x[i]=(x[i]+now)%n+1;
		sort(x+1,x+5);
		int l=1,r=len,res;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(x[1],x[2],x[3],x[4],mid))
				res=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",now=B[res]);
	}
}