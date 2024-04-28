#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define VC vector<int>
const int maxn=1e5+5;
VC E[maxn];
int tot,L[maxn],R[maxn],n,A[maxn],C[maxn],B[maxn],ans[maxn];
struct BIT
{
	int C[maxn];
	BIT(){memset(C,0,sizeof C);}
	void Add(int x,int y){while(x<maxn)C[x]+=y,x+=x&-x;}
	int sum(int x){int res=0;while(x)res+=C[x],x-=x&-x;return res;}
}T;
void dfs(int now)
{
	L[now]=++tot;
	for(int i=0;i<E[now].size();++i)dfs(E[now][i]);
	R[now]=tot;
}
namespace solve_1
{
	int len;
	void dfs(int now)
	{
		ans[now]-=T.sum(len)-T.sum(A[now]-1);
		for(int i=0;i<E[now].size();++i)dfs(E[now][i]);
		ans[now]+=T.sum(len)-T.sum(A[now]-1);T.Add(A[now],1);
	}
	void solve()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
		sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
		for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B;
		for(int i=2,x;i<=n;++i)scanf("%d",&x),E[x].push_back(i);
		dfs(1);for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	}
}
namespace solve_2
{
	int n,ans[maxn];
	struct $
	{
		int id,x;
		bool operator <($ _)const{return x>_.x;}
	}P[maxn];
	void solve()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&P[i].x),P[i].id=i;
		for(int i=2,x;i<=n;++i)scanf("%d",&x),E[x].push_back(i);
		::dfs(1);sort(P+1,P+n+1);
		for(int i=1;i<=n;++i)
		{
			ans[P[i].id]=T.sum(R[P[i].id])-T.sum(L[P[i].id]);
			T.Add(L[P[i].id],1);
		}
		for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	}

}
namespace solve_3
{
	const int maxS=500;
	int len,blk[maxn],bl[maxS],br[maxS],S;
	int getnum(int block,int x)
	{
		return br[block]-(upper_bound(B+bl[block],B+br[block]+1,x)-B)+1;
	}
	int query(int x,int l,int r)
	{
		int res=0;
		if(blk[l]!=blk[r])
		{
			for(int i=l;i<=br[blk[l]];++i)if(C[i]>x)++res;
			for(int i=blk[l]+1;i<blk[r];++i)res+=getnum(i,x);
			for(int i=bl[blk[r]];i<=r;++i)if(C[i]>x)++res;
		}
		else for(int i=l;i<=r;++i)if(C[i]>x)++res;
		return res;
	}
	void solve()
	{
		scanf("%d",&n);S=sqrt(n*log2(n));
		for(int i=1;i<=n;++i)
			scanf("%d",&A[i]),
			blk[i]=(i-1)/S+1;
		for(int i=2,x;i<=n;++i)
			scanf("%d",&x),E[x].push_back(i);
		len=blk[n];::dfs(1);
		for(int i=1;i<=n;++i)
			C[L[i]]=B[L[i]]=A[i];
		for(int i=1;i<=len;++i)
		{
			bl[i]=i*S-S+1,br[i]=i*S;
			if(br[i]>n)br[i]=n;
			sort(B+bl[i],B+br[i]+1);
		}
		for(int i=1;i<=n;++i)
			printf("%d\n",query(A[i],L[i],R[i]));
	}
}
namespace solve_4
{
	#define ls p<<1
	#define rs p<<1|1
	void Merge(VC&A,VC B,VC C)
	{
		A.clear();
		int p=0,q=0,len1=B.size(),len2=C.size();
		while(p<len1||q<len2)
		{
			if(q>=len2||p<len1&&B[p]<C[q])A.push_back(B[p++]);
			else A.push_back(C[q++]);
		}
	}
	inline int Getnum(VC V,int x)
	{
		return V.end()-upper_bound(V.begin(),V.end(),x);
	}
	struct Seg
	{
		struct $
		{
			int l,r;VC V;
			$(){l=r=0,V.clear();}
		}tree[maxn<<2];
		void build(int l,int r,int p)
		{
			tree[p].l=l;tree[p].r=r;
			if(l==r){tree[p].V.push_back(B[l]);return ;}
			int mid=l+r>>1;build(l,mid,ls);build(mid+1,r,rs);
			Merge(tree[p].V,tree[ls].V,tree[rs].V);
		}
		int query(int l,int r,int x,int p)
		{
			if(tree[p].l==l&&tree[p].r==r)
				return Getnum(tree[p].V,x);
			int mid=tree[p].l+tree[p].r>>1;
			if(mid>=r)return query(l,r,x,ls);
			else if(mid<l)return query(l,r,x,rs);
			return query(l,mid,x,ls)+query(mid+1,r,x,rs);
		}
	}T;
	void solve()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&A[i]);
		for(int i=2,x;i<=n;++i)scanf("%d",&x),E[x].push_back(i);
		::dfs(1);for(int i=1;i<=n;++i)B[L[i]]=A[i];
		T.build(1,n,1);
		for(int i=1;i<=n;++i)
			printf("%d\n",T.query(L[i],R[i],A[i],1));

	}
	#undef ls
	#undef rs
}
int main()
{
	solve_1::solve();
}