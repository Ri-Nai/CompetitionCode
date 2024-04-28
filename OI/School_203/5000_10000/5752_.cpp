#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5;
LL F[maxn];int n,m;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
struct Seg
{
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
	struct node
	{
		LL L,R,len,Lsum,Rsum,sum,ans,Add;
		node(){L=R=len=Lsum=Rsum=sum=ans=Add=0;}
	}Tree[maxn<<2];
	void Change(int p,int x)
	{
		LL &len=Tree[p].len;
		Tree[p].Add+=x;

		Tree[p].sum+=len*x;
		Tree[p].ans+=F[len]*x;

		Tree[p].Lsum+=(len+1)*len/2*x;
		Tree[p].Rsum+=(len+1)*len/2*x;
	}
	node Up(node B,node C)
	{
		node A;
		A.L=B.L;A.R=C.R;
		A.len=A.R-A.L+1;

		A.sum=B.sum+C.sum;

		A.Lsum=B.Lsum+C.Lsum+C.len*B.sum;
		A.Rsum=C.Rsum+B.Rsum+B.len*C.sum;

		A.ans=B.Rsum*C.len+C.Lsum*B.len;
		A.ans+=B.ans+C.ans;
		return A;
	}
	void Down(int p)
	{
		if(!Tree[p].Add)return;
		Change(ls,Tree[p].Add);
		Change(rs,Tree[p].Add);
		Tree[p].Add=0;
	}
	void build(int L,int R,int p)
	{
		Tree[p].len=R-L+1;
		Tree[p].L=L;Tree[p].R=R;
		if(L==R)return;
		build(L,mid,ls);
		build(mid+1,R,rs);
	}
	void updata(int L,int R,int l,int r,int x,int p)
	{
		if(L==l&&R==r)
		{
			Change(p,x);
			return;
		}
		Down(p);
		if(r<=mid)updata(L,mid,l,r,x,ls);
		else if(l>mid)updata(mid+1,R,l,r,x,rs);
		else updata(L,mid,l,mid,x,ls),updata(mid+1,R,mid+1,r,x,rs);
		Tree[p]=Up(Tree[ls],Tree[rs]);
	}
	node query(int L,int R,int l,int r,int p)
	{
		if(L==l&&R==r)return Tree[p];
		Down(p);
		if(r<=mid)return query(L,mid,l,r,ls);
		else if(l>mid)return query(mid+1,R,l,r,rs);
		else return Up(query(L,mid,l,mid,ls),query(mid+1,R,mid+1,r,rs));
	}
}T;
int main()
{

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		F[i]=F[i-1]+1ll*i*(i+1)/2;
		printf("%lld\n",F[i]);
	}
	char tmp[2];int L,R,x;
	T.build(1,--n,1);
	while(m--)
	{
		scanf("%s%d%d",&tmp,&L,&R);--R;
		if(tmp[0]=='C')scanf("%d",&x),T.updata(1,n,L,R,x,1);
		else
		{
			LL res=T.query(1,n,L,R,1).ans;
			LL Deno=1ll*(R-L+1)*(R-L+2)/2;
			LL tmp=gcd(res,Deno);
			printf("%lld/%lld\n",res/tmp,Deno/tmp);
		}
	}
}