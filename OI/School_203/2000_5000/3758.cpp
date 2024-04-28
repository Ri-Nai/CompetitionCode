#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=1e7+5;
int n,m,q;
namespace solve_50
{
	int ls[maxm],rs[maxm],cnt[maxm],sum[maxm],
	tree[maxn],A[maxn],B[maxn],tot;
	#define mid (L+R>>1)
	void build(int L,int R,int &rt)
	{
		rt=++tot;if(L==R){return ;}
		build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
	}
	void updata(int L,int R,int x,int ot,int &rt)
	{
		rt=++tot;cnt[rt]=cnt[ot]+1;
		sum[rt]=sum[ot]+x;
		ls[rt]=ls[ot];rs[rt]=rs[ot];
		if(L==R)return;
		if(x<=mid)updata(L,mid,x,ls[ot],ls[rt]);
		else updata(mid+1,R,x,rs[ot],rs[rt]);
	}
	int query(int L,int R,int lt,int rt,int k)
	{
		if(L==R)return ((k-1)/L+1);
		int now=sum[rs[rt]]-sum[rs[lt]];
		if(k<=now)return query(mid+1,R,rs[lt],rs[rt],k);
		if(k-now<=sum[ls[rt]]-sum[ls[lt]])
			return query(L,mid,ls[lt],ls[rt],k-now)+cnt[rs[rt]]-cnt[rs[lt]];
		return -1;
	}
	#undef mid
	void solve()
	{
		build(1,1000,tree[0]);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&A[i]);
			updata(1,1000,A[i],tree[i-1],tree[i]);
		}
		while(q--)
		{
			int x1,x2,y1,y2,h;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
			int ans=query(1,1000,tree[y1-1],tree[y2],h);
			if(ans!=-1)printf("%d\n",ans);
			else puts("Poor QLW");
		}
	}
}
namespace solve_20
{
	int P[205][205],Sum[205][205][1005],cnt[205][205][1005];
	void solve()
	{
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&P[i][j]);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=1000;++k)
					cnt[i][j][k]=cnt[i][j-1][k]+cnt[i-1][j][k]-cnt[i-1][j-1][k];
				++cnt[i][j][P[i][j]];
			}
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=1000;++k)
					Sum[i][j][k]=cnt[i][j][k]*k;
				for(int k=999;k;--k)
				{
					Sum[i][j][k]+=Sum[i][j][k+1];
					cnt[i][j][k]+=cnt[i][j][k+1];
				}
			}
		while(q--)
		{
			int x1,x2,y1,y2,h,l=1,r=1000,ans=-1,sum;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
			while(l<=r)
			{
				int mid=l+r>>1;
				int k=Sum[x2][y2][mid]-Sum[x2][y1-1][mid]-
				Sum[x1-1][y2][mid]+Sum[x1-1][y1-1][mid];
				if(k>=h)l=mid+1,ans=mid,sum=k;
				else r=mid-1;
			}
			if(ans==-1)puts("Poor QLW");
			else
			{
				int res=cnt[x2][y2][ans]-cnt[x2][y1-1][ans]-
				cnt[x1-1][y2][ans]+cnt[x1-1][y1-1][ans];
				if(sum>h)res-=(sum-h)/ans;
				printf("%d\n",res);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&m,&n,&q);
	if(m==1)solve_50::solve();
	else solve_20::solve();
}