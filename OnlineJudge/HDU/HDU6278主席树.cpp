#include<bits/stdc++.h>
#define mid (L+R>>1)
using namespace std;
const int maxn=1e5+5,maxm=4e6+5;
int T,n,m,tot,A[maxn],RT[maxn],
ls[maxm],rs[maxm],sum[maxm];
void build(int L,int R,int &rt)
{
	rt=++tot;ls[rt]=rs[rt]=sum[rt]=0;
	if(L==R)return;
	build(L,mid,ls[rt]);
	build(mid+1,R,rs[rt]);
}
void updata(int L,int R,int x,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot]+1;
	ls[rt]=ls[ot],rs[rt]=rs[ot];
	if(L==R)return;
	if(x<=mid)updata(L,mid,x,ls[ot],ls[rt]);
	else updata(mid+1,R,x,rs[ot],rs[rt]);
}
int query(int L,int R,int lt,int rt,int x)
{
	if(L==R)return L;
	int now=sum[rs[rt]]-sum[rs[lt]];
	if(x+now>mid)return query(mid+1,R,rs[lt],rs[rt],x);
	else return query(L,mid,ls[lt],ls[rt],x+now);
}
void solve()
{
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	tot=0;build(1,n,RT[0]);
	for(int i=1;i<=n;++i)updata(1,n,A[i],RT[i-1],RT[i]);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,n,RT[l-1],RT[r],0));
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))solve();
}