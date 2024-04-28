#include<bits/stdc++.h>
using namespace std;
#define	ls p<<1
#define rs p<<1|1
#define uint unsigned
#define Lson L,mid,ls
#define Rson mid+1,R,rs
#define Mid int mid=L+R>>1
#define LR int L=1,int R=sz,int p=1
const int N=1e5+5,M=1.5e5+5,T=4e5+5;
const uint P=19260817;uint pw[N];
int n,m,sz,op[M],A[M],B[M],now;char s[N],tmp[2];
struct node{int num;uint h;node(){num=h=0;}}Tr[T];
node Up(node L,node R)
{
	node res;
	res.h=L.h*pw[R.num]+R.h;
	res.num=L.num+R.num;
	return res;
}
void Build(LR)
{
	Tr[p].num=R-L+1;if(L==R)return ;
	Mid;Build(Lson);Build(Rson);
}
void Rebuild(LR)
{
	if(L==R)
		return (void)(Tr[p].h=Tr[p].num?s[++now]:0);
	Mid;Rebuild(Lson);Rebuild(Rson);
	Tr[p]=Up(Tr[ls],Tr[rs]);
}
int Find(int x,LR)
{
	if(L==R)return L;Mid;
	if(Tr[ls].num>=x)return Find(x,Lson);
	return Find(x-Tr[ls].num,Rson);
}
void Del(int x,LR)
{
	--Tr[p].num;
	if(L==R)return ;Mid;
	if(x<=mid)Del(x,Lson);
	else Del(x,Rson);
}
void Updata(int x,int y,LR)
{
	if(L==R)return (void)(Tr[p].num=1,Tr[p].h=y);Mid;
	if(x<=mid)Updata(x,y,Lson);
	else Updata(x,y,Rson);
	Tr[p]=Up(Tr[ls],Tr[rs]);
}
node Query(int l,int r,LR)
{
	if(L==l&&r==R)return Tr[p];Mid;
	if(r<=mid)return Query(l,r,Lson);
	if(l>mid)return Query(l,r,Rson);
	return Up(Query(l,mid,Lson),Query(mid+1,r,Rson));
}
void _Query(int id,int len)
{
	int l=Find(A[id]),r=Find(B[id]),L=1,R=len,ans=0;
	while(L<=R)
	{
		Mid;int ld=Find(A[id]+mid-1),rd=Find(B[id]+mid-1);
		if(Query(l,ld).h==Query(r,rd).h)L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%s%d",s+1,&m);
	sz=n=strlen(s+1);
	for(int i=1;i<=m;++i)
	{
		scanf("%s",tmp);
		char c=*tmp;scanf("%d",&A[i]);
		if(c=='Q')op[i]=1,scanf("%d",&B[i]);
		else
		{
			scanf("%s",tmp);
			B[i]=*tmp-'a';
			if(c=='R')op[i]=2;
			else op[i]=3,++sz,++A[i];
		}
	}
	Build();pw[0]=1;
	for(int i=m;i;--i)
		if(op[i]!=1)
		{
			A[i]=Find(A[i]);
			if(op[i]==3)Del(A[i]);
		}
		else if(A[i]>B[i])swap(A[i],B[i]);
	for(int i=1;i<=n;++i)
		pw[i]=pw[i-1]*P,s[i]-='a';
	Rebuild();
	for(int i=1;i<=m;++i)
	{
		if(op[i]!=1)Updata(A[i],B[i]);
		else _Query(i,Tr[1].num-B[i]+1);
	}
}