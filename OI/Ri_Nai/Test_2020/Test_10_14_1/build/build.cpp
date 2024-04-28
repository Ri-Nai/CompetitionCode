#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int n,P[2][N];
typedef long long LL;
inline void ToMin(LL &x,LL y){y<x&&(x=y);}
LL dp[2][2][N],S[2][N],G1[2][N],G2[2][N],inf;
void init(int p)
{
	for(int i=1;i<=n;++i)
	{
		S[p][i]=S[p][i-1]+P[p][i];
		G1[p][i]=G1[p][i-1]+P[p][i]*i;
	}
	for(int i=n;i>=1;--i)
		G2[p][i]=G2[p][i+1]+P[p][i]*(n-i+1);
}
LL Sum(int p,int L,int R)
{
	if(L<=R)return G1[p][R]-G1[p][L-1]-(S[p][R]-S[p][L-1])*L;
	return G2[p][R]-G2[p][L+1]-(S[p][L]-S[p][R-1])*(n-L+1);
}
void work(int ps,int cur,int p)
{
	for(int i=0;i<ps;++i)
	{
		if(i==0)
			ToMin(dp[cur][p^1][ps-1],Sum(p^1,ps,1)+P[p][ps]);
		else
		{
			LL now=dp[cur^1][p][i];
			if(now==inf)continue;
			ToMin(dp[cur][p][i],now+P[p^1][ps]*(ps-i));
			int mid=((ps+i)>>1)+1;
			LL diff=-Sum(p^1,i,ps-1)+Sum(p^1,i,mid-1)+Sum(p^1,ps,mid);
			ToMin(dp[cur][p^1][ps-1],now+diff+P[p][ps]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)scanf("%d%d",&P[0][i],&P[1][i]);
	init(0);init(1);
	int cur=1;
	memset(dp,0x3f,sizeof dp);
	inf=dp[0][0][0];
	for(int i=2;i<=n;++i)
	{
		cur^=1;
		memset(dp[cur],inf,sizeof dp[cur]);
		work(i,cur,0);work(i,cur,1);
	}
	LL ans=inf;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=1;++j)
			ToMin(ans,dp[cur][j][i]);
	printf("%lld\n",ans);
}
/*
从爆搜中我们已经发现了一个实质性的作用
就是找到这个的前驱和后继.
在dp的时候,可以在建立后继的过程中改变
所以只需要记录前驱就可以了
dp[N][2][N]第二维记录这一个是乒乓还是排球,第一维记录当前的楼层,第三维记录另一个的前驱的位置 
比较恶心的一个地方在于初始化,因为最初是没有前驱的,并且可能会保持很久都没有前驱
另一个比较恶心的地方在于转移.暂时还没想好 
可以先初始化成无穷大然后再再后面清理这个的数值?

另一个比较恶心的地方在于这个地方卡n^2处理i->j之间的人数的内存 
好像甚至卡我这个dp数组的内存,可能是可以滚动吗?

dp[i][1][j]=dp[i-1][1][j]+P[0][i]*(i-j);
dp[i][0][i-1]=min(dp[i-1][1][j]+P[1][i]-SumA((i+j/2)~j))-SumA((i+j/2)~i)s;
是至于dp[i-1]有关,故可以使用滚动数组

另一个地方就是这个Sum,爷暂时还没想好怎么优化掉内存 
*/
