#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
struct P
{
	int x,y;
	bool operator <(const P&_)const
	{
		return x<_.x;
	}
	void read()
	{
		scanf("%d%d",&x,&y);
	}
	LL Get(int k)
	{
		return 1ll*x*k+y;
	}
}A[N],B[N];
struct Que
{
	int k,id;
	bool operator < (const Que &_)const
	{
		return k>_.k;
	}
}Q[N];
int n,m,top;
long long ans[N];
bool chk(P a,P b,P c)
{
	return 1ll*(b.y-a.y)*(c.x-b.x)>1ll*(c.y-b.y)*(b.x-a.x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)A[i].read();
	for(int i=1;i<=m;++i)scanf("%d",&Q[i].k),Q[i].id=i;
	sort(A+1,A+n+1);sort(Q+1,Q+m+1);
	B[++top]=A[1];B[++top]=A[2];
	for(int i=3;i<=n;++i)
	{
		while(top>1&&!chk(B[top-1],B[top],A[i]))--top;
		B[++top]=A[i];
	}
	for(int i=1;i<=m;++i)
	{
		while(top>1&&B[top-1].Get(Q[i].k)>B[top].Get(Q[i].k))--top;
		ans[Q[i].id]=B[top].Get(Q[i].k);
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
}