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
int n,m,top;
bool chk(P a,P b,P c)
{
	return 1ll*(b.y-a.y)*(c.x-b.x)>1ll*(c.y-b.y)*(b.x-a.x);
}
LL solve(int k)
{
	int l=1,r=top;
	LL ans=max(B[l].Get(k),B[r].Get(k));
	while(l<=r)
	{
		int mid=l+r>>1,rm=mid+r>>1;
		LL fm=B[mid].Get(k),fmm=B[rm].Get(k);
		if(fm<=fmm)l=mid+1,ans=max(ans,fmm);
		else r=rm-1,ans=max(ans,fm);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)A[i].read();
	sort(A+1,A+n+1);
	B[++top]=A[1];B[++top]=A[2];
	for(int i=3;i<=n;++i)
	{
		while(top>1&&!chk(B[top-1],B[top],A[i]))--top;
		B[++top]=A[i];
	}
	for(int k;m--;)
	{
		scanf("%d",&k);
		printf("%lld\n",solve(k));
	}
}