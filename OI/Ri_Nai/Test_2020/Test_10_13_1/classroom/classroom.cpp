#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
bool Nai;
const int N=1e6+5;
int n,m,A[N],W[N],L[N],R[N];
long long diff[N];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
namespace FW
{
	// #define Lson L,mid,p<<1
	// #define Rson mid+1,R,p<<1|1
	// long long mn[N<<2],lz[N<<2];
	// int Build(int L=1,int R=n,int p=1)
	// {
	// 	if(L==R)return mn[p]=A[L];
	// 	int mid=L+R>>1;
	// 	return mn[p]=min(Build(Lson),Build(Rson));
	// }
	// inline void change(int p,long long x)
	// {
	// 	lz[p]+=x;
	// 	mn[p]-=x;
	// }
	// inline void Down(int p)
	// {
	// 	long long &t=lz[p];
	// 	change(p<<1,t);
	// 	change(p<<1|1,t);
	// 	t=0;
	// }
	// int Query(int l,int r,int x,int L=1,int R=n,int p=1)
	// {
	// 	if(l==L&&R==r){change(p,x);return mn[p]>=0;}
	// 	Down(p);int mid=L+R>>1;
	// 	bool ans=0;
	// 	if(r<=mid)ans=Query(l,r,x,Lson);
	// 	else if(l>mid)ans=Query(l,r,x,Rson);
	// 	else ans=Query(l,mid,x,Lson)&Query(mid+1,r,x,Rson);
	// 	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	// 	return ans;
	// }
	// void Solve()
	// {
	// 	Build(1,n,1);
	// 	for(int i=1,x,l,r;i<=m;++i)
	// 	{
	// 		x=rd();l=rd();r=rd();
	// 		if(!Query(l,r,x))
	// 		{
	// 			printf("-1\n%d\n",i);
	// 			return ;
	// 		}
	// 	}
	// 	puts("0");
	// }
}
bool Ri;
bool chk(int t)
{
	for(int i=1;i<=n;++i)diff[i]=A[i]-A[i-1];
	for(int i=1;i<=t;++i)
		diff[L[i]]-=W[i],diff[R[i]+1]+=W[i];
	long long now=0;
	for(int i=1;i<=n;++i)
	{
		now+=diff[i];
		if(now<0)return 1;
	}
	return 0;
}
int main()
{
	// FILE("classroom");
	// printf("%f\n",(&Ri-&Nai)/1024./1024);
	n=rd();m=rd();
	for(int i=1;i<=n;++i)A[i]=rd();
	for(int i=1;i<=m;++i)W[i]=rd(),L[i]=rd(),R[i]=rd();
	int l=1,r=m,res=-1,mid;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(chk(mid))r=mid-1,res=mid;
		else l=mid+1;
	}
	if(~res)puts("-1"),printf("%d\n",res);
	else puts("0");
	FCLS();
}
/*
4 3
2 5 4 3
2 1 3
3 2 4
4 2 4

*/