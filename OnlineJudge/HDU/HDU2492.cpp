#include<cstdio>
#include<cstring>
#define Clear(A) memset(A,0,sizeof A)
const int maxn=1e5+5;
int A[maxn],C[maxn],n,Lmin[maxn],Lmax[maxn],Rmin[maxn],Rmax[maxn];
void Add(int id,int x)
{
	while(id<maxn)C[id]+=x,id+=id&-id;
}
int sum(int id)
{
	int res=0;
	while(id)res+=C[id],id-=id&-id;
	return res;
}
void solve()
{
	scanf("%d",&n);long long ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);Clear(C);
	for(int i=1;i<=n;++i)Add(A[i],1),Lmax[i]=sum(1e5)-sum(A[i]),Lmin[i]=sum(A[i]-1);Clear(C);
	for(int i=n;i>=1;--i)Add(A[i],1),Rmax[i]=sum(1e5)-sum(A[i]),Rmin[i]=sum(A[i]-1);
	for(int i=1;i<=n;++i)ans+=1ll*Lmin[i]*Rmax[i]+1ll*Lmax[i]*Rmin[i];
	printf("%lld\n",ans);

}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}