#include<cstdio>
#include<cstring>
const int maxn=8e4+5;
int n,A[maxn],C[maxn],ans[maxn];
void Add(int x,int y)
{
	while(x<maxn)C[x]+=y,x+=x&-x;
}
int sum(int x)
{
	int res=0;
	while(x)res+=C[x],x-=x&-x;
	return res;
}
void query(int id)
{
	int l=1,r=n,res;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(sum(mid)<A[id]+1)l=mid+1;
		else r=mid-1,res=mid;
	}
	Add(res,-1);ans[id]=res;
}
void solve()
{
	Add(1,1);
	for(int i=2;i<=n;++i)Add(i,1),scanf("%d",&A[i]);
	for(int i=n;i;--i)query(i);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
}
int main()
{
	while(~scanf("%d",&n))solve();
}