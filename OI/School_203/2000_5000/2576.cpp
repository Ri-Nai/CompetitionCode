#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
	bool chk(P _,int k)
	{
		return 1ll*x*k+y>1ll*_.x*k+_.y;
	}
}A[N],B[N];
int n,m,top;
bool chk(P a,P b,P c)
{
	return 1ll*(b.y-a.y)*(c.x-b.x)>1ll*(c.y-b.y)*(b.x-a.x);
}
long long solve(int k)
{
	int l=1,r=top,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(mid==1||B[mid].chk(B[mid-1],k))
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	// Rn_1(ans);
	return 1ll*B[ans].x*k+B[ans].y;
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