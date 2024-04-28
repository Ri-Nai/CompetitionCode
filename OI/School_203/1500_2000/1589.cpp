#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
const int N=2e5+5;
int f[N],n,Q;
struct node
{
	int mx,lmx,rmx,len;
	node(){mx=lmx=rmx=len=1;}
	node(int _,int __,int ___,int ____){mx=_,lmx=__,rmx=___,len=____;}
}Tree[N<<2];
node Up(node L,node R,int lp,int rp)
{
	node res;
	res.len=L.len+R.len;
	res.mx=max(L.mx,R.mx);
	res.lmx=L.lmx;
	res.rmx=R.rmx;
	if(lp!=rp)
	{
		if(L.lmx==L.len)res.lmx+=R.lmx;
		if(R.rmx==R.len)res.rmx+=L.rmx;
		res.mx=max(res.mx,L.rmx+R.lmx);
	}
	res.mx=max(res.mx,max(res.lmx,res.rmx));
	return res;
}
void build(int L=1,int R=n,int p=1)
{
	if(L==R){Tree[p]=node(1,1,1,1);return;}
	build(Lson);build(Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1],f[mid],f[mid+1]);
}
void updata(int x,int L=1,int R=n,int p=1)
{
	if(L==R)return;
	if(x<=mid)updata(x,Lson);
	else updata(x,Rson);
	Tree[p]=Up(Tree[p<<1],Tree[p<<1|1],f[mid],f[mid+1]);
}
int main()
{
	scanf("%d%d",&n,&Q);
	build();
	while(Q--)
	{
		int x;scanf("%d",&x);
		f[x]^=1;updata(x);
		printf("%d\n",Tree[1].mx);
	}
}
