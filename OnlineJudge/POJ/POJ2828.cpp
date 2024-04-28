#include<cstdio>
#include<cstring>
const int maxn=2e5+5;
int n,A[maxn],B[maxn],C[maxn],ans[maxn];
void Add(int x,int y){while(x<maxn)C[x]+=y,x+=x&-x;}
int sum(int x){int res=0;while(x)res+=C[x],x-=x&-x;return res;}
void query(int id)
{
	int l=1,r=n,res;
	while(l<=r)
	{
		int mid=l+r>>1;
		//printf("%d %d\n",l,r);
		if(sum(mid)<A[id])l=mid+1;
		else r=mid-1,res=mid;
	}
//	printf("%d %d\n",id,res);
	Add(res,-1);ans[res]=B[id];
}
void solve()
{
	memset(C,0,sizeof C);
	for(int i=1;i<=n;++i)Add(i,1),scanf("%d%d",&A[i],&B[i]),++A[i];
	for(int i=n;i;--i)query(i);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);puts("");
}
int main()
{
	while(~scanf("%d",&n))solve();
}