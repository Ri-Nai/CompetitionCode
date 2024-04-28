#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=2e5+5;
int n,m,k,A[maxn];
int Add[maxn<<2],sum[maxn<<2];
void change(int p,int t)
{
	sum[p]+=t;Add[p]+=t;
}
void Down(int p)
{
	int &t=Add[p];if(!t)return ;
	change(ls,t);change(rs,t);t=0;
}
void updata(int l,int r,int x,int p=1,int L=1,int R=n)
{
	if(L==l&&r==R){sum[p]+=x,Add[p]+=x;return;}Down(p);
	int mid=L+R>>1;
	if(r<=mid)updata(l,r,x,ls,L,mid);
	else if(l>mid)updata(l,r,x,rs,mid+1,R);
	else updata(l,mid,x,ls,L,mid),updata(mid+1,r,x,rs,mid+1,R);
	sum[p]=max(sum[ls],sum[rs]);
}
int query(int l,int r,int p=1,int L=1,int R=n)
{
	if(L==l&&r==R)return sum[p];Down(p);
	int mid=L+R>>1;
	if(r<=mid)return query(l,r,ls,L,mid);
	else if(l>mid)return query(l,r,rs,mid+1,R);
	else return max(query(l,mid,ls,L,mid),query(mid+1,r,rs,mid+1,R));
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),updata(i,min(n,i+k-1),A[i]);
	for(int p,x,y;m--;)
	{
		scanf("%d%d%d",&p,&x,&y);
		if(p==0)
			updata(x,min(n,x+k-1),y-A[x]),A[x]=y;
		else if(p==1)
			updata(x,min(n,x+k-1),A[y]-A[x]),
			updata(y,min(n,y+k-1),A[x]-A[y]),
			swap(A[x],A[y]);
		else printf("%d\n",query(x+k-1,y));
	}
}