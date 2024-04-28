#include<cstdio>
#include<algorithm>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=5e4+5;
int n,m;
struct Professional_Team
{
	int sum[maxn<<2],Add[maxn<<2],
	Lsum[maxn<<2],Rsum[maxn<<2],len[maxn<<2];
	void Up(int p)
	{
		sum[p]=max(sum[ls],sum[rs]);
		sum[p]=max(sum[p],Rsum[ls]+Lsum[rs]);
		Lsum[p]=Lsum[ls];Rsum[p]=Rsum[rs];
		if(Lsum[ls]==len[ls])Lsum[p]+=Lsum[rs];
		if(Rsum[rs]==len[rs])Rsum[p]+=Rsum[ls];
	}
	void Change(int p,int x)
	{
		Add[p]=x;
		Lsum[p]=Rsum[p]=sum[p]=len[p]*(x-1);
	}
	void down(int p)
	{
		if(!Add[p])return;
		Change(ls,Add[p]);
		Change(rs,Add[p]);
		Add[p]=0;
	}
	void build(int L,int R,int p)
	{
		len[p]=R-L+1;Add[p]=0;
		if(L==R)
		{
			sum[p]=Lsum[p]=Rsum[p]=1;
			return ;
		}
		int mid=L+R>>1;
		build(L,mid,ls);
		build(mid+1,R,rs);
		Up(p);
	}
	void updata(int L,int R,int l,int r,int a,int p)
	{
		if(l==L&&R==r)
		{
			Change(p,a);
			return;
		}
		down(p);int mid=L+R>>1;
		if(r<=mid)updata(L,mid,l,r,a,ls);
		else if(l>mid)updata(mid+1,R,l,r,a,rs);
		else updata(L,mid,l,mid,a,ls),updata(mid+1,R,mid+1,r,a,rs);
		Up(p);
	}
	int query(int L,int R,int x,int p)
	{
		if(L==R)return L;
		down(p);int mid=L+R>>1;
		//printf("%d %d %d %d %d %d %d\n",L,R,x,p,sum[p],sum[ls],sum[rs]);
		if(sum[ls]>=x)return query(L,mid,x,ls);
		else if(Rsum[ls]+Lsum[rs]>=x)return mid-Rsum[ls]+1;
		else if(sum[rs]>=x)return query(mid+1,R,x,rs);
		else return 0;
	}
}Team;
int main()
{
	scanf("%d%d",&n,&m);
	Team.build(1,n,1);
	while(m--)
	{
		int flag,x,y;
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d",&x);
			int L=Team.query(1,n,x,1);
			printf("%d\n",L);
			if(L)Team.updata(1,n,L,L+x-1,1,1);
		}
		else
		{
			scanf("%d%d",&x,&y);
			Team.updata(1,n,x,x+y-1,2,1);
		}
	}
}