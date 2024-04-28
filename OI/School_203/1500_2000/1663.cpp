#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
const int N=1e6+5;
int mn[N<<2],n,k,A[N];
void build(int L=1,int R=n-1,int p=1)
{
	if(L==R)return (void)(mn[p]=A[L+1]-A[L]);
	build(Lson);build(Rson);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
int Query(int l,int r,int L=1,int R=n-1,int p=1)
{
	if(l==L&&R==r)return mn[p];
	if(r<=mid)return Query(l,r,Lson);
	if(l>mid)return Query(l,r,Rson);
	return min(Query(l,mid,Lson),Query(mid+1,r,Rson));
}
int main()
{
	scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&A[i]);
    sort(A+1,A+n+1);k=n-k;
    build();int ans=1e9;
    for(int i=k;i<=n;++i)
        ans=min(ans,A[i]-A[i-k+1]+Query(i-k+1,i-1));
    printf("%d\n",ans);
}