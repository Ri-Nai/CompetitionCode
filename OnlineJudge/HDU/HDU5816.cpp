#include<cstdio>
#include<cstring>
#define LL long long
int P,n,m,B[25];
LL dp[1<<21],fact[25];
void init()
{
	fact[0]=1;for(int i=1;i<=20;++i)fact[i]=fact[i-1]*i;
}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void solve()
{
	scanf("%d%d%d",&P,&n,&m);int K=n+m;
	for(int i=0;i<m;++i)scanf("%d",&B[i]);
	memset(dp,0,sizeof dp);dp[0]=1;
	for(int i=0;i<(1<<K);++i)
		if(dp[i])
		{
			int NA=0,NB=0,Hit=0;
			for(int j=0;j<m;++j)if(i&(1<<j))++NB,Hit+=B[j];
			for(int j=m;j<K;++j)if(i&(1<<j))++NA;
			if(Hit<P&&NA+1>NB)
				for(int j=0;j<K;++j)if(!(1<<j&i))dp[1<<j|i]+=dp[i];
		}
	LL ans1=0,ans2=fact[K];
	//printf("%lld %lld %lld\n",ans1,ans2,fact[K]);
	for(int i=0;i<(1<<K);++i)
		if(dp[i])
		{
			int NA=0,NB=0,Hit=0;
			for(int j=0;j<m;++j)if(i&(1<<j))++NB,Hit+=B[j];
			for(int j=m;j<K;++j)if(i&(1<<j))++NA;
			if(Hit>=P)ans1+=dp[i]*fact[K-NA-NB];

		}
	LL k=gcd(ans1,ans2);
	printf("%lld/%lld\n",ans1/k,ans2/k);
}
int main()
{
	int T;scanf("%d",&T);
	init();while(T--)solve();
}