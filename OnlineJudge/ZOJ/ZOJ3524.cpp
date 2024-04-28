#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define pr std::pair<int,int>
#define mp std::make_pair
const int maxn=605;
std::vector<pr>E[maxn];
int n,m,V,X,weigh[maxn],val[maxn],in[maxn];
bool mark[maxn];
struct $
{
	int val;long long cost;
	$(){val=0;cost=0ll;}
	$(int _val,long long _cost):val(_val),cost(_cost){}
	bool operator <(const $&_)const
	{
		return val==_.val?cost>_.cost:val<_.val;
	}
}dp[maxn][2005],ans,tmp;
void bfs_mark()
{
	std::queue<int>Q;
	Q.push(X);mark[X]=1;
	while(!Q.empty())
	{
		int now=Q.front();Q.pop();
		for(int i=0;i<E[now].size();++i)
		{
			int v=E[now][i].first;
			if(!mark[v])Q.push(v),mark[v]=1;
		}
	}
	for(int i=1;i<=n;++i)if(!mark[i])
		for(int j=0;j<E[i].size();++j)
			--in[E[i][j].first];
}
void bfs_dp()
{
	std::queue<int>Q;
	Q.push(X);ans=$();
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int i=weigh[u];i<=V;++i)
		{
			//tmp=($){dp[u][i-weigh[u]].val+val[u],dp[u][i-weigh[u]].cost};
			tmp=$(dp[u][i-weigh[u]].val+val[u],dp[u][i-weigh[u]].cost);
			dp[u][i]=std::max(dp[u][i],tmp);
		}
		for(int i=0;i<=V;++i)ans=std::max(ans,dp[u][i]);
		for(int i=0;i<E[u].size();++i)
		{
			int v=E[u][i].first,w=E[u][i].second;
			for(int j=0;j<=V;++j)
			{
				tmp=($){dp[u][j].val,dp[u][j].cost+1ll*w*j};
				dp[v][j]=std::max(dp[v][j],tmp);
			}
			--in[v];if(!in[v])Q.push(v);
		}
	}
	printf("%d\n",ans.cost);
}
void Clear()
{
	for(int i=0;i<maxn;++i)E[i].clear();
	memset(mark,0,sizeof mark);
	memset(in,0,sizeof in);
	for(int i=0;i<maxn;++i)
		for(int j=0;j<=2000;++j)
			dp[i][j]=$();

}
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&V,&X))
	{
		Clear();
		for(int i=1;i<=n;++i)scanf("%d%d",&weigh[i],&val[i]);
		for(int i=1,u,v,w;i<=m;++i)
			scanf("%d%d%d",&u,&v,&w),
			E[u].push_back(mp(v,w)),++in[v];
		bfs_mark();bfs_dp();
	}
}

