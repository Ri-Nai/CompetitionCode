#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=2e5+5;
int mx[maxn<<2],h,w,n;
void build(int L,int R,int p)
{
	if(L==R){mx[p]=w;return;}
	int mid=L+R>>1;
	build(L,mid,ls);
	build(mid+1,R,rs);
	mx[p]=max(mx[ls],mx[rs]);
}
void updata(int L,int R,int x,int y,int p)
{
	if(L==R){mx[p]-=y;return ;}
	int mid=L+R>>1;
	if(x<=mid)updata(L,mid,x,y,ls);
	else updata(mid+1,R,x,y,rs);
	mx[p]=max(mx[ls],mx[rs]);
}
int query(int L,int R,int x,int p)
{
	if(L==R){return L;}
	int mid=L+R>>1;
	if(mx[ls]>=x)return query(L,mid,x,ls);
	else return query(mid+1,R,x,rs);
}
int main()
{
	while(~scanf("%d%d%d",&h,&w,&n))
	{
		if(h>n)h=n;
		build(1,h,1);
		while(n--)
		{
			int a;scanf("%d",&a);
			if(mx[1]<a)puts("-1");
			else
			{
				int ans=query(1,h,a,1);
				updata(1,h,ans,a,1);
				printf("%d\n",ans);
			}
		}
	}
}