#include<cstdio>
#define ls p<<1
#define rs p<<1|1
#define mid (Tree[p].L+Tree[p].R>>1)
const int maxn=1e5+5;
struct $
{	
	
	int L,R,len,L0,R0,L1,R1,C0,C1,S0,S1,m1,m2,m3;
	// $(){
	// 	m1=m2=m3=0;
	// }
	//Tree[p]=($){L,R,1,!A[L],!A[L],A[L],A[L],!A[L],A[L],!A[L],A[L],0,0,0};
}Tree[maxn<<2];
int n,m,A[maxn];
inline int max(const int &a,const int &b){return a>b?a:b;}
inline void swap(int &a,int &b){int t=a;a=b;b=t;}
$ Up($&x,$ y,$ z)
{
	//$ x;
	//x.m1=x.m2=x.m3
	x.L=y.L,x.R=z.R,
	x.len=z.R-y.L+1;

	x.S0=y.S0+z.S0;
	x.S1=y.S1+z.S1;

	x.L0=(!y.S1)?(y.len+z.L0):(y.L0);
	x.L1=(!y.S0)?(y.len+z.L1):(y.L1);

	x.R0=(!z.S1)?(z.len+y.R0):(z.R0);
	x.R1=(!z.S0)?(z.len+y.R1):(z.R1);

	x.C0=max(max(y.C0,z.C0),y.R0+z.L0);
	x.C1=max(max(y.C1,z.C1),y.R1+z.L1);
	//if(x.m1||x.m2||x.m3)puts("1");
	return x;
}
///////////////////////////////////////////////////////////////////
void build(int L,int R,int p)
{
	Tree[p].L=L,Tree[p].R=R,Tree[p].len=R-L+1;
	Tree[p].m1=Tree[p].m2=Tree[p].m3=0;

	if(L==R)

		//Tree[p]=($){L,R,1,!A[L],!A[L],A[L],A[L],!A[L],A[L],!A[L],A[L],0,0,0};
	{
		Tree[p].S0=Tree[p].L0=Tree[p].R0=Tree[p].C0=!A[L];
		Tree[p].S1=Tree[p].L1=Tree[p].R1=Tree[p].C1=A[L];
	}
	else
		build(L,mid,ls),build(mid+1,R,rs),Up(Tree[p],Tree[ls],Tree[rs]);
//	if(L==R)printf("%d",Tree[p].S1);
}
///////////////////////////////////////////////////////////////////
void change0(int p)
{
	int R=Tree[p].R,L=Tree[p].L,len=Tree[p].len;
	Tree[p]=($){L,R,len,len,len,0,0,len,0,len,0,1,0,0};
}
////////////////////////////////////////////////////////////////
void change1(int p)
{
	int R=Tree[p].R,L=Tree[p].L,len=Tree[p].len;
	Tree[p]=($){L,R,len,0,0,len,len,0,len,0,len,0,1,0};
}
//////////////////////////////////////////////////////////////
void Reverse(int p)
{
	$&x=Tree[p];
	swap(x.L0,x.L1);swap(x.R0,x.R1);
	swap(x.C0,x.C1);swap(x.S0,x.S1);
	swap(x.m1,x.m2);
	x.m3^=1;
}
///////////////////////////////////////////////////////////////
void Down(int p)
{	
	if(Tree[p].m3)Tree[p].m3=0,Reverse(ls),Reverse(rs);
	if(Tree[p].m1)Tree[p].m1=0,change0(ls),change0(rs);
	if(Tree[p].m2)Tree[p].m2=0,change1(ls),change1(rs);
	
}
///////////////////////////////////////////////////////////////
void update(int L,int R,int flag,int p)
{
	if(Tree[p].L==L&&Tree[p].R==R)
	{
		if(flag==0)change0(p);
		if(flag==1)change1(p);
		if(flag==2)Reverse(p);
	}
	else
	{
		Down(p);
		if(R<=mid)update(L,R,flag,ls);
		else if(L>mid)update(L,R,flag,rs);
		else update(L,mid,flag,ls),update(mid+1,R,flag,rs);
		Up(Tree[p],Tree[ls],Tree[rs]);
	}
}
$ query(int L,int R,int p)
{
	if(Tree[p].L==L&&R==Tree[p].R)
		return Tree[p];
	Down(p);$ tmp;
	if(R<=mid)return query(L,R,ls);
	if(L>mid)return query(L,R,rs);
	return Up(tmp,query(L,mid,ls),query(mid+1,R,rs));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	build(1,n,1);
	//printf("%d",Tree[17].L1);
	// for(int j=1;j<=n;j++)
	// 	printf("%d ",
	// 	query(j,j,1)
	// 	.C1);
	// puts("");
	for(int i=1,flag,L,R;i<=m;++i)
	{
		scanf("%d%d%d",&flag,&L,&R);
		++L,++R;
		if(flag<3)update(L,R,flag,1);
		else if(flag==3)printf("%d\n",query(L,R,1).S1);
		else printf("%d\n",query(L,R,1).C1);
		
	}
}