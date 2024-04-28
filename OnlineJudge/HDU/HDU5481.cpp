#include<cstdio>
#include<algorithm>
const int maxn=1e5+5,HD=1e9+7;
struct $
{
	int pos,mark;
	bool operator <($ _)const{return pos<_.pos;}
}A[maxn<<1];
long long fact[maxn];
void init()
{
	fact[0]=1;for(int i=1;i<maxn;++i)fact[i]=fact[i-1]*2%HD;
}
void solve()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&A[i].pos,&A[2*n-i+1].pos),
		A[i].mark=1,A[2*n-i+1].mark=-1;
	std::sort(A+1,A+2*n+1);
	int cnt=0;long long	ans=0;
	for(int i=1;i<=2*n;++i)
	{
		(ans+=(A[i].pos-A[i-1].pos)*(fact[n]-fact[n-cnt]+HD)%HD)%=HD;
		cnt+=A[i].mark;
	}
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	init();while(T--)solve();
}