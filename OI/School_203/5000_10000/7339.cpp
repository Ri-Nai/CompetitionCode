#include<cstdio>
#include<vector>
#include<algorithm>
#define ls p<<1
#define rs p<<1|1
const int maxn=2e5+5;
struct ${int l,id;};
std::vector<$>E[maxn];
int n,q,A[maxn],ans[maxn],tree[maxn<<2];
void update(int l,int r,int x,int y,int p)
{
    if(l==r){tree[p]=y;return;}
    int mid=l+r>>1;
    if(x<=mid)update(l,mid,x,y,ls);
    else update(mid+1,r,x,y,rs);
    tree[p]=std::min(tree[ls],tree[rs]);
}
int query(int l,int r,int x,int p)
{
    if(l==r)return l;
    int mid=l+r>>1;
    if(tree[ls]<x)return query(l,mid,x,ls);
    else return query(mid+1,r,x,rs);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    for(int i=1,l,r;i<=q;++i)
        scanf("%d%d",&l,&r),E[r].push_back(($){l,i});
    for(int i=1;i<=n;++i)
    {
        update(0,maxn,A[i],i,1);
        for(int j=0;j<E[i].size();++j)
            ans[E[i][j].id]=query(0,maxn,E[i][j].l,1);
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
}
