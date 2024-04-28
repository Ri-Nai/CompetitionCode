#include<queue>
#include<cstdio>
#include<algorithm>
#define ls p<<1
#define rs p<<1|1
const int maxn=105;
int n,T,t[maxn],pos[maxn],id[maxn],ans;
struct $
{
	int id,t;
	bool operator < (const $&_)const{return t<_.t;}
}A[105];

struct node
{
    int L,R,sum,cnt;
}tree[105<<2];
void Up(int p)
{
    tree[p].sum=tree[ls].sum+tree[rs].sum;
    tree[p].cnt=tree[ls].cnt+tree[rs].cnt;
}
void build(int l,int r,int p)
{
    tree[p].L=l,tree[p].R=r;
    if(l==r)tree[p].cnt=tree[p].sum=0;
    else 
    {
	    int mid=l+r>>1;
	    build(l,mid,ls);
	    build(mid+1,r,rs);
	    Up(p);
    }
}
void update(int x,int y,int p)
{
    if(tree[p].L==x&&tree[p].R==x)
        tree[p].sum=y,tree[p].cnt=1;
    else
    {
	    int mid=(tree[p].L+tree[p].R)>>1;
	    if(x<=mid)update(x,y,ls);
	    else update(x,y,rs);
	    Up(p);
    }
}
int query(int tot,int p)
{
    if(tree[p].L==tree[p].R)
        if(tree[p].sum<=tot)return tree[p].cnt;
        else return 0;
    if(tree[ls].sum<=tot)return tree[ls].cnt+query(tot-tree[ls].sum,rs);
    else return query(tot,ls);
}
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]),A[i]=($){i,t[i]};
	for(int i=1;i<=n;++i)scanf("%d",&pos[i]);
	std::sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)id[A[i].id]=i;
	for(int i=1;i<=n;++i)
	{
		build(1,n,1);
		for(int j=i;j<=n;++j)
		{
			update(id[j],t[j],1);
			ans=std::max(ans,query(T-pos[j]+pos[i],1));
		}
	}
	printf("%d\n",ans);
}