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
void updata(int L,int R,int l,int r,int x,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot];
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==l&&r==R){sum[rt]+=x;return ;}
	if(r<=mid)updata(L,mid,l,r,x,ls[ot],ls[rt]);
	else if(l>mid)updata(mid+1,R,l,r,x,rs[ot],rs[rt]);
	else updata(L,mid,l,mid,x,ls[ot],ls[rt]),updata(mid+1,R,mid+1,r,x,rs[ot],rs[rt]);
}
long long query(int L,int R,int x,int rt)
{
	if(L==R)return sum[rt];
	if(x<=mid)return query(L,mid,x,ls[rt])+sum[rt];
	else return query(mid+1,R,x,rs[rt])+sum[rt];
}
void solve()
{

	scanf("%d",&n);pre.clear();tot=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	build(1,n,RT[0]);
	for(int i=1,tmp;i<=n;++i)
	{
		updata(1,n,pre[A[i]]+1,i,A[i],RT[i-1],RT[i]);
		pre[A[i]]=i;
	}
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",query(1,n,l,RT[r]));
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}