#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int A[N],k,n,m;
struct kk
{
	int mark,mn,num;
	int l[32],r[32];
	kk(){mn=1e9,num=mark=0;}
}Tree[N<<2];
void Up(kk &M,kk &L,kk &R)
{
	M.mark=L.mark|R.mark;
	M.mn=min(L.mn,R.mn);
	for(int i=1;i<=L.num;++i)M.l[i]=L.l[i];
	for(int i=1;i<=R.num;++i)M.r[i]=R.r[i];
	M.num=L.num;
	for(int i=1;i<=R.num;++i)
		if(!(L.mark&1<<A[R.l[i]]))
			M.l[++M.num]=R.l[i];
	M.num=R.num;
	for(int i=1;i<=L.num;++i)
		if(!(R.mark&1<<A[L.r[i]]))
			M.r[++M.num]=L.r[i];
	if(M.num!=k)return ;
	int now=0,pos=L.num,sum[32]={};
	for(int i=1;i<=L.num;++i)
		if(sum[A[L.r[i]]]++==0)++now;
	for(int i=1;i<=R.num;++i)
	{
		if(sum[A[R.l[i]]]++==0)++now;
		if(now==k)
		{
			while(pos&&sum[A[L.r[pos]]]>1)--sum[A[L.r[pos--]]];
			M.mn=min(M.mn,R.l[i]-L.r[pos]+1);
		}
	}
}
void build(int L=1,int R=n,int p=1)
{
	if(L==R)
	{
		Tree[p].num=1;
		Tree[p].mark=1<<A[L];
		Tree[p].l[1]=Tree[p].r[1]=L;
		return ;
	}
	int mid=L+R>>1;
	build(L,mid,p<<1);build(mid+1,R,p<<1|1);
	Up(Tree[p],Tree[p<<1],Tree[p<<1|1]);
}
void updata(int x,int L=1,int R=n,int p=1)
{
	if(L==R)
		return (void)Tree[p].mark=1<<A[L];
	int mid=L+R>>1;
	if(x<=mid)updata(x,L,mid,p<<1);
	else updata(x,mid+1,R,p<<1|1);
	Up(Tree[p],Tree[p<<1],Tree[p<<1|1]);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),--A[i];
	for(build();m--;)
	{
		int op,u;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&u);scanf("%d",&A[u]);
			--A[u];updata(u);
		}
		else printf("%d\n",Tree[1].num==k?Tree[1].mn:-1);
	}

}