#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5,maxm=6e7+5;
int h1;
int cnt[maxm],RT[maxn],ls[maxm],rs[maxm];
LL sum[maxm];
int n,m,tot,mx;
vector<int>E[maxn];
int h2;
#define mid (L+R>>1)
void build(int &rt,int L=1,int R=mx)
{
	rt=++tot;if(L==R)return;
	build(ls[rt],L,mid);build(rs[rt],mid+1,R);
}
void updata(int x,int ot,int &rt,int L=1,int R=mx)
{
	cnt[rt=++tot]=cnt[ot]+(x>0?1:-1);
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	sum[rt]=sum[ot]+x;
	if(L==R)return;
	if(abs(x)<=mid)updata(x,ls[ot],ls[rt],L,mid);
	else updata(x,rs[ot],rs[rt],mid+1,R);
}
LL query(int x,int rt,int L=1,int R=mx)
{
	if(L==R)return 1ll*L*x;
	if(x<=cnt[ls[rt]])return query(x,ls[rt],L,mid);
	else return query(x-cnt[ls[rt]],rs[rt],mid+1,R)+sum[ls[rt]];
}
#undef mid
int main()
{
	//printf("%f\n",(&h2-&h1)/1024.0/1024);
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<=n;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		E[a].push_back(c);
		E[b+1].push_back(-c);
		mx=max(mx,c);
	}
	build(RT[0]);
	for(int i=1;i<=m;++i)
	{
		RT[i]=RT[i-1];
		for(int j=0;j<E[i].size();++j)
			updata(E[i][j],RT[i],RT[i]);
	}
	LL ans=1;
	for(int i=1,x,a,b,c;i<=m;++i)
	{
		scanf("%d%d%d%d",&x,&a,&b,&c);
		int k=1+(ans*a+b)%c;
		if(cnt[RT[x]]<=k)ans=sum[RT[x]];
		else ans=query(k,RT[x]);
		printf("%lld\n",ans);
	}
}