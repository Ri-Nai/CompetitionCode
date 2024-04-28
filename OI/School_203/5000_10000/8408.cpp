#include<bits/stdc++.h>
#define mid (L+R>>1)
using namespace std;
const int maxn=1e5+5,maxm=5e6+5;
int n,A[maxn],m,ls[maxm],rs[maxm],val[maxm],tot,RT[maxn];
void updata(int L,int R,int x,int ot,int &rt)
{
    rt=++tot;
    ls[rt]=ls[ot],rs[rt]=rs[ot];
    val[rt]=val[ot]+x;
    if(L==R)return ;
    if(x<=mid)updata(L,mid,x,ls[ot],ls[rt]);
    else updata(mid+1,R,x,rs[ot],rs[rt]);
}
int query(int L,int R,int l,int r,int lt,int rt)
{
    if(L==l&&R==r)return val[rt]-val[lt];
    if(r<=mid)return query(L,mid,l,r,ls[lt],ls[rt]);
    if(l>mid)return query(mid+1,R,l,r,rs[lt],rs[rt]);
    return query(L,mid,l,mid,ls[lt],ls[rt])+query(mid+1,R,mid+1,r,rs[lt],rs[rt]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    for(int i=1;i<=n;++i)updata(1,1e9,A[i],RT[i-1],RT[i]);
    scanf("%d",&m);
    for(int i=1,l,r;i<=m;++i)
    {
        scanf("%d%d",&l,&r);
        int ans=1;
        while(1)
        {
            int tmp=query(1,1e9,1,ans,RT[l-1],RT[r]);
            if(tmp<ans)break;
            else ans=tmp+1;
        }
        printf("%d\n",ans); 
    }
}