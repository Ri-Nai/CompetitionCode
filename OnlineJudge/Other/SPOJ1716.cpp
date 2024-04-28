#include<cstdio>
#define ll long long
#define ls p<<1
#define rs p<<1|1
const int maxn=1e5+5;
int n,m,A[maxn],res;
struct node
{
    int L,R,sum,mx,Lmx,Rmx;
} tree[maxn<<2];
inline int max(const int &a,const int &b)
{
    return a>b?a:b;
}
void Up(node &C,node A,node B)
{
    C.mx=max(A.mx,B.mx);
    C.mx=max(C.mx,A.Rmx+B.Lmx);
    C.Lmx=max(A.Lmx,A.sum+B.Lmx);
    C.Rmx=max(B.Rmx,B.sum+A.Rmx);
    C.sum=A.sum+B.sum;
}
void build(int L,int R,int p)
{
    tree[p].L=L,tree[p].R=R;
    if(L==R)
    {
        tree[p]=(node){L,R,A[L],A[L],A[L],A[L]};
        return;
    }
    int mid=L+R>>1;
    build(L,mid,ls);
    build(mid+1,R,rs);
    Up(tree[p],tree[ls],tree[rs]);
}
void update(int x,int a,int p)
{
    if(tree[p].L==tree[p].R)
    {
        tree[p]=(node){tree[p].L,tree[p].R,a,a,a,a};
        return;
    }
    int mid=tree[p].L+tree[p].R>>1;
    if(x<=mid)update(x,a,ls);
    else update(x,a,rs);
    Up(tree[p],tree[ls],tree[rs]);
}
node query(int L,int R,int p)
{
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p];
    int mid=tree[p].L+tree[p].R>>1;
    if(R<=mid)return query(L,R,ls);
    if(L>mid)return query(L,R,rs);
    node A=query(L,mid,ls);
    node B=query(mid+1,R,rs);
    node C;
    Up(C,A,B);
    return C;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&A[i]);
    build(1,n,1);
    scanf("%d",&m);
    int c,l,r;
    while(m--)
    {
        scanf("%d%d%d",&c,&l,&r);
        if(c>0)printf("%d\n",query(l,r,1).mx);
        else update(l,r,1);
    }
}