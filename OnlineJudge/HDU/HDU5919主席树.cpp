#include<bits/stdc++.h>
#define mid (L+R>>1)
using namespace std;
const int maxn=2e5+5,maxm=8e6+5;
int sum[maxm],ls[maxm],rs[maxm],RT[maxm],tot;
int A[maxn],last[maxn],n,m,ans[maxn];
void build(int L,int R,int &rt)
{
	rt=++tot;sum[rt]=0;if(L==R)return;
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
}
void updata(int L,int R,int x,int y,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot]+y;
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==R)return;
	if(x<=mid)updata(L,mid,x,y,ls[ot],ls[rt]);
	else updata(mid+1,R,x,y,rs[ot],rs[rt]);
}
int GetSum(int L,int R,int l,int r,int rt)
{
	if(L==l&&R==r)return sum[rt];
	if(r<=mid)return GetSum(L,mid,l,r,ls[rt]);
	if(l>mid)return GetSum(mid+1,R,l,r,rs[rt]);
	return GetSum(L,mid,l,mid,ls[rt])+GetSum(mid+1,R,mid+1,r,rs[rt]);
}
int query(int L,int R,int x,int rt)
{
	if(L==R)return L;
	int now=sum[ls[rt]];
	if(x<=now)return query(L,mid,x,ls[rt]);
	else return query(mid+1,R,x-now,rs[rt]);
}
void solve(int cas)
{
	scanf("%d%d",&n,&m);tot=0;
	memset(last,0,sizeof last);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	build(1,n,RT[n+1]);
	for(int i=n,tmp;i;--i)
	{
		if(!last[A[i]])
			updata(1,n,i,1,RT[i+1],RT[i]);
		else 
			updata(1,n,last[A[i]],-1,RT[i+1],tmp),
			updata(1,n,i,1,tmp,RT[i]);
		last[A[i]]=i;
	}
	for(int i=1,l,r,k;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		l=(l+ans[i-1])%n+1;
		r=(r+ans[i-1])%n+1;
		//printf("%d  %d\n",l,r);
		if(l>r)swap(l,r);
		k=GetSum(1,n,l,r,RT[l]);
		//printf("```%d\n",k);
		k=(k+1)>>1;
		ans[i]=query(1,n,k,RT[l]);
	}
	printf("Case #%d:",cas);
	for(int i=1;i<=m;++i)printf(" %d",ans[i]);
	puts("");
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}