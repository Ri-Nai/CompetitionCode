#include<cstdio>
#include<cstring>
const int maxn=3e5+5;
int n,m,A[maxn],C[maxn];
long long ans;
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
void query(int x)
{
	int l=1,r=n,res;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(sum(mid)<x)l=mid+1;
		else r=mid-1,res=mid;
	}
	Add(res,-1);ans+=res;
}
void solve(int id)
{
	scanf("%d%d",&n,&m);ans=0;memset(C,0,sizeof C);
	for(int i=1;i<=n;++i)Add(i,1);
	for(int i=1,x;i<=m;++i)
		scanf("%d",&x),query(x);
	printf("Case %d: %lld\n",id,ans);
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}