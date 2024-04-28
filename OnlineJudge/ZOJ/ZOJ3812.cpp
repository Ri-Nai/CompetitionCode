#include<map>
#include<cstdio>
#include<cstring>
#define ULL unsigned long long
const int maxT=2e5+5,maxn=405,maxw=55;
int t[maxn],w[maxn],p[maxT][maxw],Qt[maxn],Qw[maxn],mxT,n,Q;
ULL dp[maxT];std::map<ULL,int>key;
void solve()
{
	memset(p,-1,sizeof p);
	memset(dp,0,sizeof dp);
	dp[0]=1;mxT=0;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)scanf("%d%d",&w[i],&t[i]);
	for(int i=1;i<=Q;++i)scanf("%d%d",&Qw[i],&Qt[i]),mxT=(Qt[i]>mxT?Qt[i]:mxT);
	for(int i=1;i<=n;++i)
		for(int j=mxT;j>=t[i];--j)
		{
			ULL tmp=dp[j-t[i]];
			tmp<<=w[i];//左移w[i]位
			tmp|=dp[j];//dp[j]的值
			tmp^=dp[j];//只留能改变dp[j]的值	
			dp[j]|=tmp;
			while(tmp)
			{
				ULL k=tmp&-tmp;
				int tw=key[k];
				p[j][tw]=i;
				tmp-=k;
			}
		}
	for(int i=1;i<=Q;++i)
	{
		int W=Qw[i],T=Qt[i];
		if(dp[T]>>W&1)
		{
			int k=p[T][W];
			printf("%d",k);
			T-=t[k],W-=w[k];
			while(W)
			{
				int k=p[T][W];
				printf(" %d",k);
				T-=t[k],W-=w[k];
			}
			puts("");
		}
		else puts("No solution!");
	}
}
int main()
{
	for(int i=0;i<=50;++i)key[1ull<<i]=i;
	int T;scanf("%d",&T);
	while(T--)solve();
}