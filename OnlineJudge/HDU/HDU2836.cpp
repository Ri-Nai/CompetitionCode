#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1e5+5,mod=9901;
int n,m,len,A[maxn],B[maxn],ans=0,C[maxn];
void Add(int x,int y){while(x<maxn)(C[x]+=y)%=mod,x+=x&-x;}
int sum(int x){int res=0;while(x)(res+=C[x])%=mod,x-=x&-x;return res;}
void in_put()
{
	memset(C,0,sizeof C);ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	std::sort(B+1,B+n+1);len=std::unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=std::lower_bound(B+1,B+len+1,A[i])-B;
}
void solve()
{
	in_put();
	for(int i=1;i<=n;++i)
	{
		int now=A[i],
			l=std::lower_bound(B+1,B+len+1,B[A[i]]-m)-B,
			r=std::upper_bound(B+1,B+len+1,B[A[i]]+m)-B-1,
			tmp=(sum(r)-sum(l-1)+1+mod)%mod;
		(ans+=tmp)%=mod;
		Add(now,tmp);
	}
	printf("%d\n",((ans-n)%mod+mod)%mod);
}
int main()
{
	while(~scanf("%d%d",&n,&m))solve();
}