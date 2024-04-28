#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=2010;
struct BIT
{
	int C[maxn];
	void clear(){memset(C,0,sizeof C);}
	void ToMax(int x,int y){while(x<maxn)C[x]=std::max(C[x],y),x+=x&-x;}
	int GetMax(int x){int res=0;while(x)res=std::max(C[x],res),x-=x&-x;return res;}
}dp[maxn];
int A[maxn],B[maxn],tmp[maxn],n,m;
void solve()
{
	for(int i=0;i<maxn;++i)dp[i].clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&A[i],&B[i]),tmp[i]=A[i],tmp[2*n-i+1]=B[i];
	std::sort(tmp+1,tmp+1+2*n);int len=std::unique(tmp+1,tmp+2*n+1)-tmp-1;
	for(int i=1;i<=n;++i)
		A[i]=std::lower_bound(tmp+1,tmp+len+1,A[i])-tmp,
		B[i]=std::lower_bound(tmp+1,tmp+len+1,B[i])-tmp;
	int ans=1;
	for(int i=1;i<=n;++i)
		for(int j=m;~j;--j)
		{
			int sum=dp[j].GetMax(A[i]-1)+1;
			if(sum>ans)ans=sum;
			dp[j].ToMax(A[i],sum);
			if(j)
			{
				int sum=dp[j-1].GetMax(B[i]-1)+1;
				if(sum>ans)ans=sum;
				dp[j].ToMax(B[i],sum);
			}
		}
	printf("%d\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}
