#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxS=505;
int n,m,A[maxn],L[maxn],R[maxn],pos[maxn],len,
	S,bl[maxS],br[maxS],blk[maxn],tot,dep[maxn];
vector<int>E[maxn];
struct node
{
	int dep,num,sum;
	bool operator<(node _)const
	{
		return dep<_.dep;
	}
}B[maxn],C[maxn];
void dfs(int now,int fa)
{
	L[now]=++tot;pos[tot]=now;dep[now]=dep[fa]+1;
	for(int i=0;i<E[now].size();++i)
		dfs(E[now][i],now);
	R[now]=tot;
}
int Lower_Bound(int l,int r,int x)
{
	int res=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(B[mid].dep<=x)res=mid,l=mid+1;
		else r=mid-1;
	}
	return B[res].sum;
}
int query(int x,int l,int r)
{
	int res=0;
	if(blk[l]!=blk[r])
	{
		for(int i=l;i<=br[blk[l]];++i)if(C[i].dep<=x)res+=C[i].num;
		for(int i=blk[l]+1;i<blk[r];++i)res+=Lower_Bound(bl[i],br[i],x);
		for(int i=bl[blk[r]];i<=r;++i)if(C[i].dep<=x)res+=C[i].num;
	}
	else for(int i=l;i<=r;++i)if(C[i].dep<=x)res+=C[i].num;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);S=sqrt(n*log2(n));
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),blk[i]=(i-1)/S+1;
	for(int i=2,x;i<=n;++i)
		scanf("%d",&x),
		E[x].push_back(i);
	dfs(1,0);len=blk[n];
	for(int i=1;i<=n;++i)
	{
		B[L[i]].num=C[L[i]].num=A[i];
		B[L[i]].dep=C[L[i]].dep=dep[i];
	}
	for(int i=1;i<=blk[n];++i)
	{
		bl[i]=(i-1)*S+1;br[i]=i*S;
		if(br[i]>n)br[i]=n;
		sort(B+bl[i],B+br[i]+1);
		B[bl[i]].sum=B[bl[i]].num;
		for(int j=bl[i]+1;j<=br[i];++j)
			B[j].sum=B[j-1].sum+B[j].num;
	}
	while(m--)
	{
		int h,x;
		scanf("%d%d",&x,&h);
		printf("%d\n",query(dep[x]+h,L[x],R[x]));
	}
}