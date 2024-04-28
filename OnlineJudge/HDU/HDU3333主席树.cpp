#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
const int maxn=3e4+5,maxm=1.5e6+5;
int n,m,A[maxn];
int tot,RT[maxn],ls[maxm],rs[maxm];
long long sum[maxm];//Prefessional Team
map<int,int>pre;
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
long long query(int L,int R,int l,int r,int rt)
{
	if(L==l&&r==R)return sum[rt];
	if(r<=mid)return query(L,mid,l,r,ls[rt]);
	else if(l>mid)return query(mid+1,R,l,r,rs[rt]);
	return query(L,mid,l,mid,ls[rt])+query(mid+1,R,mid+1,r,rs[rt]);
}
void solve()
{

	scanf("%d",&n);pre.clear();tot=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	build(1,n,RT[0]);
	for(int i=1,tmp;i<=n;++i)
	{
		if(!pre[A[i]])updata(1,n,i,A[i],RT[i-1],RT[i]);
		else
			updata(1,n,pre[A[i]],-A[i],RT[i-1],tmp),
			updata(1,n,i,A[i],tmp,RT[i]);
		pre[A[i]]=i;
	}
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",query(1,n,l,r,RT[r]));
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}