#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
#define LR int L=1,int R=n,int p=1
const int N=5e5+5;
struct Ri_Nai{int l,id;};
vector<Ri_Nai>Q[N];
int n,q,A[N],ans[N];
int mx[N<<2],lz[N<<2],Ld[N<<2];
void build(LR)
{
	Ld[p]=mx[p]=lz[p]=0;
	if(L==R)return;
	build(Lson);build(Rson);
}
void change(int p,int t)
{
	lz[p]=max(lz[p],t);
	if(Ld[p])mx[p]=max(mx[p],t-Ld[p]+1);
}
void Up(int p)
{
	Ld[p]=Ld[p<<1]?Ld[p<<1]:Ld[p<<1|1];
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void Down(int p)
{
	int &t=lz[p];if(!t)return;
	change(p<<1,t);change(p<<1|1,t);t=0;
}
void updada(int l,int r,int w,LR)
{
	if(l==L&&R==r)return change(p,w);Down(p);
	if(r<=mid)updada(l,r,w,Lson);
	else if(l>mid)updada(l,r,w,Rson);
	else updada(l,mid,w,Lson),updada(mid+1,r,w,Rson);Up(p);
}
void uptata(int x,int y,LR)
{
	if(L==R)return (void)(Ld[p]=y);Down(p);
	if(x<=mid)uptata(x,y,Lson);
	else uptata(x,y,Rson);Up(p);
}
int query(int l,int r,LR)
{
	if(l==L&&R==r)return mx[p];Down(p);
	if(r<=mid)return query(l,r,Lson);
	if(l>mid)return query(l,r,Rson);
	return max(query(l,mid,Lson),query(mid+1,r,Rson));
}
int stx[N],stn[N],tpx,tpn;
void Insert(int id)
{
	while(tpx&&A[id]>=A[stx[tpx]])--tpx;
	while(tpn&&A[id]<A[stn[tpn]])
		uptata(stn[tpn--],0);
	int Lx=stx[tpx]+1;
	stn[++tpn]=stx[++tpx]=id;
	uptata(id,id);updada(Lx,id,id);
}
void solve()
{
	build();tpn=tpx=0;
	for(int i=1;i<=n;++i)
	{
		Insert(i);
		for(int j=0;j<Q[i].size();++j)
		{
			int &id=Q[i][j].id;
			ans[id]=max(ans[id],query(Q[i][j].l,i));
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;++i)
		scanf("%d%d",&l,&r),
		Q[r].push_back((Ri_Nai){l,i});
	solve();for(int i=1;i<=n;++i)A[i]=-A[i];solve();
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
}