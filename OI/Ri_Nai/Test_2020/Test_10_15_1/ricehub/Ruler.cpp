#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL B,Sum[N];int ans,n,L,A[N];
inline bool chk(int l,int mid,int r)
{
    return 1ll*(mid-l+1-r+mid)*A[mid]-(Sum[mid]-Sum[l-1])+Sum[r]-Sum[mid]<=B;
}
int main()
{
    scanf("%d%d%lld",&n,&L,&B);
    for(int i=1;i<=n;++i)
        scanf("%d",&A[i]),Sum[i]=Sum[i-1]+A[i];
    for(int i=1,r=0;i<=n;++i)
    {
        while(r<n&&chk(i,r+i+1>>1,r+1))++r;
        ans=max(ans,r-i+1);
    }
    printf("%d\n",ans);
}
