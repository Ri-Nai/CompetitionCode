#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,L,ans,A[maxn],B[maxn],vis[maxn],
C[maxn],tot,tree[maxn<<2]; 
void down(int p)
{
	int &t=tree[p];
	if(t==0)return ;
	tree[p<<1]=t;
	tree[p<<1|1]=t;
	t=0;
}
void update(int L,int R,int l,int r,int k,int p)
{
	if(L==l && R==r)
	{
		tree[p]=k;
		return ;
	}
	down(p);
	int mid=L+R>>1;
	if(r<=mid)update(L,mid,l,r,k,p<<1);
	else if(l>mid)update(mid+1,R,l,r,k,p<<1|1);
	else
		update(L,mid,l,mid,k,p<<1),
		update(mid+1,R,mid+1,r,k,p<<1|1);
}
int query(int L,int R,int x,int p)
{
	if(tree[p])return tree[p];
	if(L==R)return 0;
	int mid=L+R>>1;
	if(x<=mid)return query(L,mid,x,p<<1);
	else return query(mid+1,R,x,p<<1|1);  
} 
int main()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&A[i],&B[i]);
		C[++tot]=A[i];
		C[++tot]=B[i];
		C[++tot]=--B[i]; 
	}   
	sort(C+1,C+tot+1);
	tot=unique(C,C+tot+1)-C-1;
	for(int i=1;i<=n;++i)
	{
		A[i]=lower_bound(C,C+tot+1,A[i])-C+1;
		B[i]=lower_bound(C,C+tot+1,B[i])-C+1;
		update(1,tot,A[i],B[i],i,1);
	} 
	for(int i=1;i<=tot;++i)vis[query(1,tot,i,1)]=1;
	for(int i=1;i<=n;++i)if(vis[i])ans++;
	printf("%d\n",ans);
}