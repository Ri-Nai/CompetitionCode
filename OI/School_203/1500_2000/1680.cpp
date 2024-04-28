#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
#define LR int L=1,int R=n,int p=1
const int N=2e5+5;
int n,m,B[N],A[N];
struct node
{
	int mx,mn;
}Tree[N<<2];
node Up(node L,node R)
{
	node res;
	res.mx=max(L.mx,R.mx);
	res.mn=min(L.mn,R.mn);
	return res;
}
void bulid(LR)
{
	if(L==R)
	{
		Tree[p]=(node){B[L],B[L]};
		return;
	}
	bulid(Lson);bulid(Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1]);
}
void Updata(int x,LR)
{
	if(L==R)
	{
		Tree[p]=(node){B[L],B[L]};
		return;
	}
	if(x<=mid)Updata(x,Lson);
	else Updata(x,Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1]);
}
node Query(int l,int r,LR)
{
	if(l==L&&R==r)return Tree[p];
	if(r<=mid)return Query(l,r,Lson);
	else if(l>mid)return Query(l,r,Rson);
	return Up(Query(l,mid,Lson),Query(mid+1,r,Rson));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),B[A[i]]=i;
	bulid();
	for(int op,x,y;m--;)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			B[A[x]]=y;
			B[A[y]]=x;
			Updata(A[x]);
			Updata(A[y]);
			swap(A[x],A[y]);
		}
		else 
		{
			node p=Query(x,y);
			if(y-x==p.mx-p.mn)puts("YES");
			else puts("NO");
		}
	}
}