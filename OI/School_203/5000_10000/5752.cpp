#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL sum1,sum2,sum3;
int n,m;
struct Seg
{
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
	struct node
	{
		LL sum_1,sum_2,sum_3;
		//sum_1,2,3分别表示v[i],v[i]*i,v[i]*i*i的和
		LL k_1,k_2,k_3;
		//  k_1,2,3分别表示∑1,∑i,∑i*i
		LL Add;
	}Tree[maxn<<2];
	void change(int p,int k)
	{
		Tree[p].Add+=k;
		Tree[p].sum_1+=Tree[p].k_1*k;
		Tree[p].sum_2+=Tree[p].k_2*k;
		Tree[p].sum_3+=Tree[p].k_3*k;
	}
	void Up(int p)
	{
		Tree[p].sum_1=Tree[ls].sum_1+Tree[rs].sum_1;
		Tree[p].sum_2=Tree[ls].sum_2+Tree[rs].sum_2;
		Tree[p].sum_3=Tree[ls].sum_3+Tree[rs].sum_3;
	}
	void Down(int p)
	{
		if(!Tree[p].Add)return;
		change(ls,Tree[p].Add);
		change(rs,Tree[p].Add);
		Tree[p].Add=0;
	}
	void build(int L,int R,int p)
	{
		if(L==R)
		{
			Tree[p].k_1=1;
			Tree[p].k_2=L;
			Tree[p].k_3=1ll*L*L;
			return;
		}
		build(L,mid,ls);build(mid+1,R,rs);
		Tree[p].k_1=Tree[ls].k_1+Tree[rs].k_1;
		Tree[p].k_2=Tree[ls].k_2+Tree[rs].k_2;
		Tree[p].k_3=Tree[ls].k_3+Tree[rs].k_3;
	}
	void updata(int L,int R,int l,int r,int a,int p)
	{
		if(L==l&&r==R){change(p,a);return;}
		Down(p);
		if(r<=mid)updata(L,mid,l,r,a,ls);
		else if(l>mid)updata(mid+1,R,l,r,a,rs);
		else updata(L,mid,l,mid,a,ls),updata(mid+1,R,mid+1,r,a,rs);
		Up(p);
	}
	void query(int L,int R,int l,int r,int p)
	{
		if(L==l&&r==R)
		{
			sum1+=Tree[p].sum_1;
			sum2+=Tree[p].sum_2;
			sum3+=Tree[p].sum_3;
			return ;
		}
		Down(p);
		if(r<=mid)query(L,mid,l,r,ls);
		else if(l>mid)query(mid+1,R,l,r,rs);
		else query(L,mid,l,mid,ls),query(mid+1,R,mid+1,r,rs);
	}
}T;
int main()
{
	scanf("%d%d",&n,&m);--n;
	char tmp[2];int L,R,x;
	T.build(1,n,1);
	while(m--)
	{
		scanf("%s%d%d",&tmp,&L,&R);--R;
		if(tmp[0]=='C')scanf("%d",&x),T.updata(1,n,L,R,x,1);
		else
		{
			sum1=sum2=sum3=0;
			T.query(1,n,L,R,1);
			LL res=1ll*(R-L+1-1ll*L*R)*sum1-sum3+1ll*(L+R)*sum2;
			LL Deno=1ll*(R-L+1)*(R-L+2)/2;
			LL tmp=gcd(res,Deno);
			printf("%lld/%lld\n",res/tmp,Deno/tmp);
		}
	}
}