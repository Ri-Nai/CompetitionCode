#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define pr pair<int,int>
#define mt multiset<pr>::iterator 
struct Block
{
	int v,h,id;
	bool operator <(const Block &_)const
	{
		return v<_.v;
	}
}A[N],B[N];
multiset<pr>S1,S2;
int n,ans1[N],ans2[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i].v),A[i].id=i;
	for(int i=1;i<=n;++i)scanf("%d",&A[i].h),A[i].id=i;
	for(int i=1;i<=n;++i)scanf("%d",&B[i].v),B[i].id=i;
	for(int i=1;i<=n;++i)scanf("%d",&B[i].h),B[i].id=i;
	sort(A+1,A+n+1);sort(B+1,B+n+1);
	for(int i=1,ra=1,rb=1;i<=n;++i)
	{
		while(ra<=n&&A[i].v==A[ra].v)S1.insert(pr(A[ra].h,A[ra].id)),++ra;
		while(rb<=n&&B[i].v==B[rb].v)S2.insert(pr(B[rb].h,B[rb].id)),++rb;
		if(S1.size()<S2.size())//S1的范围更小,要满足她的要求
		{
			int Ah=S1.begin()->first;
			ans1[i]=S1.begin()->second;
			S1.erase(S1.begin());
			mt it=S2.lower_bound(pr(Ah,0));
			if(it==S2.begin())return !puts("impossible");
			ans2[i]=(--it)->second;S2.erase(it);
		}
		else
		{
			int Bh=S2.begin()->first;
			ans2[i]=S2.begin()->second;
			S2.erase(S2.begin());
			mt it=S1.upper_bound(pr(Bh,n+1));
			if(it==S1.end())return !puts("impossible");
			ans1[i]=it->second;S1.erase(it);

		}
	}
	for(int i=1;i<=n;++i)printf("%d ",ans1[i]);puts("");
	for(int i=1;i<=n;++i)printf("%d ",ans2[i]);
}