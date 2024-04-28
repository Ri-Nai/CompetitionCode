#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
typedef long long LL;
struct Land
{
	LL x,y;
	LL Get(int k){return x*k+y;}
	void read(){scanf("%lld%lld",&x,&y);}
	bool operator <(const Land &_)const
	{
		return x==_.x?y<_.y:x<_.x;
	}
}A[N],Q[N];
int n,L=1,R;LL dp[N];
void pre()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)A[i].read();
	sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
	{
		if(i<n&&A[i].x==A[i+1].x)continue;
		Q[++R]=A[i];
	}n=0;
	for(int i=R,mx=0;i;--i)
	{
		if(Q[i].y<=mx)continue;
		mx=Q[i].y;A[++n]=Q[i];
	}R=0;
	//当前A数组x递减,y递增
}
bool chk(Land a,Land b,Land c)
{
	return (b.y-a.y)*(c.x-b.x)<(c.y-b.y)*(b.x-a.x);
}
int main()
{
	pre();
	Q[++R]=(Land){A[1].x,0};
	for(int i=1;i<=n;++i)
	{
		int k=A[i].y;
		while(L<R&&Q[L].Get(k)>=Q[L+1].Get(k))++L;
		dp[i]=Q[L].Get(k);
		if(i<n)
		{
			Land tmp=(Land){A[i+1].x,dp[i]};
			while(R>L&&chk(Q[R-1],Q[R],tmp))--R;
			Q[++R]=tmp;
		}
		else printf("%lld\n",dp[n]);
	}
}