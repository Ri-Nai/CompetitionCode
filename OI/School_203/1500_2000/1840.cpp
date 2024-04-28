#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;long long ans;
struct Line
{
	int x,y;
	bool operator <(const Line &_)const
	{
		return y>_.y;
	}
}A[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&A[i].x,&A[i].y),A[i].y>>=1;
	sort(A+1,A+n+1);int mx=0;
	for(int i=1;i<=n;++i)
	{
		if(i>1)ans+=1ll*mx*(A[i-1].y-A[i].y);
		mx=max(A[i].x,mx);
	}
	ans+=1ll*mx*A[n].y;
	printf("%lld\n",ans<<1);
}