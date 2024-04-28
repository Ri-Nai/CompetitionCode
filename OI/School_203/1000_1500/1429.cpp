#include<cstdio>
#include<vector>
#include<algorithm>
const int maxn=205;
struct $
{
	int x,y,t,val;
	void read(){scanf("%d%d%d%d",&x,&y,&t,&val);}
	bool operator ==($ _)const{return x*_.y==y*_.x;}
}A[maxn];
int n,T,mark[maxn],tot,dp[maxn*maxn];
std::vector<$>E[maxn];
void in_put()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)A[i].read();
	for(int i=1;i<=n;++i)
	{
		if(!mark[i])
		{
			int sum=0,sumt=0;
			mark[i]=++tot,E[tot].push_back(($){i,i,sumt+=A[i].t,sum+=A[i].val});
			for(int j=i+1;j<=n;++j)
				if(A[i]==A[j])mark[j]=tot,E[tot].push_back(($){j,j,sumt+=A[j].t,sum+=A[j].val});
		}
	}
}
int main()
{
	in_put();
	for(int i=1;i<=tot;++i)
		for(int j=T;j>=0;--j)
			for(int k=0;k<E[i].size();++k)
			{
				int V=E[i][k].t,W=E[i][k].val;
				//printf("%d %d\n",V,W);
				if(j-V>=0)dp[j]=std::max(dp[j-V]+W,dp[j]);
			}
	printf("%d\n",dp[T]);
}