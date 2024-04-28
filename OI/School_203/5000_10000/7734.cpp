#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=N<<2;
#define EOR(i,L,u) for(register int i=L.head[u],v;v=L.to[i];i=L.nxt[i])
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
#define DOR(i,a,b) for(register int i=a,i##_=b;i>=i##_;--i)
inline void ToMin(int &x,int y){y<x&&(x=y);}
inline void ToMax(int &x,int y){y>x&&(x=y);}
typedef long long LL;
LL rd()
{
	LL t=0; int c,f=0; while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
struct Bomb
{
	LL x,r,id,L,R;
	bool operator <(const Bomb &_)const
	{
		return x<_.x;
	}
	void read(int i)
	{
		x=rd(); r=rd();
		L=x-r; R=x+r; id=i;
	}
} A[N];
struct Link
{
	int to[M],nxt[M],head[N],tot;
	void reset(int n)
	{
		FOR(i,1,n)head[i]=0;tot=0;
	}
	void Add(int u,int v)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
	}
} L1,L2;
int n,stk[N],top,dfn[N],low[N],blg[N],blk,tot,L[N],R[N],ans[N],in[N];
bool vis[N];
void Tarjan(int u)
{
	vis[stk[++top]=u]=1;
	dfn[u]=low[u]=++tot;
	EOR(i,L1,u)
	if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
	else if(vis[v])low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		L[++blk]=1e9; R[blk]=0; int v;
		do
			vis[v=stk[top--]]=0,ToMin(L[blg[v]=blk],v),ToMax(R[blk],v);
		while(u!=v);
	}
}
void Solve()
{
	n=rd();
	L1.reset(n);
	blk=top=tot=0;
	FOR(i,1,n)dfn[i]=0;
	FOR(i,1,n)A[i].read(i);
	sort(A+1,A+n+1);
	FOR(i,1,n)
	{
		while(top&&A[stk[top]].R<A[i].x)--top;
		if(top)L1.Add(stk[top],i);
		while(top&&A[stk[top]].R<=A[i].R)--top;
		stk[++top]=i;
	}
	top=0;
	DOR(i,n,1)
	{
		while(top&&A[stk[top]].L>A[i].x)--top;
		if(top)L1.Add(stk[top],i);
		while(top&&A[stk[top]].L>=A[i].L)--top;
		stk[++top]=i;
	}
	top=0;
	FOR(i,1,n)if(!dfn[i])Tarjan(i);
	L2.reset(blk);
	FOR(u,1,n)EOR(i,L1,u)
		if(blg[u]^blg[v])L2.Add(blg[v],blg[u]),++in[blg[u]];
	top=0;
	FOR(i,1,blk)if(!in[i])stk[++top]=i;
	while(top)
	{
		int u=stk[top--];
		EOR(i,L2,u)
		{
			ToMin(L[v],L[u]); ToMax(R[v],R[u]);
			if(!--in[v])stk[++top]=v;
		}
	}
	FOR(i,1,n)ans[A[i].id]=R[blg[i]]-L[blg[i]]+1;
	FOR(i,1,n)printf("%d ",ans[i]);
}
int main()
{
	int T=rd();
	while(T--)Solve();
}
/*	
2
5
0 2
2 1
3 2
4 1
6 2
5
0 2
2 1
3 2
4 1
6 2
*/