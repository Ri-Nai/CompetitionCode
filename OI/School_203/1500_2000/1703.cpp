#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,mark[N];long long ans,dp[N];
int main()
{
	scanf("%d",&n);++n;
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),mark[x]=1;
	for(int i=1;i<N;++i)
	{
		if(!mark[i])continue;
		int k=sqrt(i);
		for(int j=1;j<=k;++j)
			if(i%j==0)mark[j]=mark[i/j]=1;
	}
	for(int i=1;i<N;++i)
	{
		if(!mark[i])continue;
		dp[i]+=i-1;
		for(int j=i+i;j<N;j+=i)
			dp[j]-=dp[i];//从小到大枚举,j枚举倍数,倍数-=每一个约数
		ans+=dp[i];
	}
	printf("%lld\n",ans);
}
/*
1
10
20

2*5和10是不相等的
如何处理10

19/23

只能枚举因数

2 4 5 10

4=2*2
10=2*5

12=2*2*3

2
2
3
6


5
8 9 10
7+9+8
*/