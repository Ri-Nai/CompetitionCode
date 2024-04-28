#include<deque>
#include<cstdio>
#include<cstring>
#define Fasdasd
const int maxn=5e5+5;
void read(int &t)
{
	t=0;
	int f=1,c;
	do{c=getchar();if(c=='-')f=-1;}while(c>'9'||c<'0');
	while(c>='0'&&c<='9')t=(t<<1)+(t<<3)+(c^48),c=getchar();
	t*=f;
}
struct Robot
{
	int x,s;
	void read()
	{
		::read(x);
		::read(s);
	}
}a[maxn];
int n,d,k,dp[maxn];
bool check(const int &t)
{
	int l=d-t,r=d+t,now=0;
	if(l<=0)l=1;
	std::deque<int> q;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i)
	{
		while(now<i&&a[i].x-a[now].x>=l)
		{
			if(!q.empty())
				while(!q.empty()&&dp[now]>=dp[q.back()])
					q.pop_back();
			q.push_back(now);
			++now;
		}
		while(!q.empty()&&a[i].x-a[q.front()].x>r)
			q.pop_front();
		if(!q.empty())
			dp[i]=dp[q.front()]+a[i].s;
		else dp[i]=-1e9;
		if(dp[i]>=k)
			return 1;
	}
	return 0;
}
void pre()
{
	read(n),read(d),read(k);
	for(int i=1;i<=n;++i)
		a[i].read();
}
void solve()
{
	pre();
	int l=0,r=d>a[n].x?d:a[n].x,mid,ans=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			ans=mid,
			r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
