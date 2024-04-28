#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1e5+5;
int n,A[maxn],C[maxn],ans[maxn];
void Add(int x,int y){while(x<maxn)C[x]+=y,x+=x&-x;}
int sum(int x){int res=0;while(x)res+=C[x],x-=x&-x;return res;}
void solve(int cas)
{
	memset(C,0,sizeof C);scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)Add(A[i],1),ans[A[i]]=std::max(i+A[i]-sum(A[i]),i)-std::min(A[i],i);
	printf("Case #%d:",cas);
	for(int i=1;i<=n;++i)printf(" %d",ans[i]);puts("");
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}