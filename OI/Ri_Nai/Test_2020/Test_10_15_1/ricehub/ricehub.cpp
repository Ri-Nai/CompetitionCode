#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
typedef long long LL;
int n,m,A[N],L;
LL B,Sum[N];
bool chk(int T)
{
	int now=0,r=1;
	for(int i=1;i<=n;++i)
	{
		while(r<=n&&now<T)++now,++r;
		if(r==n+1&&now<T)return 0;
		int mid=(i+r-1)>>1;
		LL Cost=1ll*(mid-i+1)*A[mid]-(Sum[mid]-Sum[i-1]);
		Cost+=Sum[r-1]-Sum[mid]-1ll*(r-mid-1)*A[mid];
		if(Cost<=B)return 1;
		--now;
	}
	return 0;
}
int main()
{
//	FILE("ricehub");
	scanf("%d%d%lld",&n,&L,&B);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		Sum[i]=Sum[i-1]+A[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	FCLS();
}
/*


5 20 6
1
2
10
12
14


时间复杂度需求nlogn
排除除树状数组外的所有数据结构
排除倍增
可能可以二分
但是只能二分答案而不是二分节点
节点的答案没有单调性 

选择的稻田一定在连续的一段区间里面
这一段区间一定是以这个区间为中点,然后就迎刃而解了? 

但是这段区间里面可能会有重叠的

23 1372 2418
540
581
632
644
645
662
688
710
710
751
833
837
838
887
902
919
944
1001
1015
1017
1020
1126
1135

*/
