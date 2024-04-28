#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define mp std::make_pair
#define pr std::pair<int,int>
const int maxn=105;
int n,m,P[maxn],L[maxn],Low,Up,ans,F[maxn];
std::vector<pr>E[105];
int dfs(int now)
{
	if(~F[now])return F[now];
	F[now]=P[now];
	for(int i=0;i<E[now].size();++i)
	{
		int id=E[now][i].first,val=E[now][i].second;
		if(L[id]>=Low&&L[id]<=Up)F[now]=std::min(F[now],val+dfs(id));
	}
	return F[now];
}
void in_put()
{
	scanf("%d%d",&m,&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d%d%d",&P[i],&L[i],&x);
		for(int j=1,t,v;j<=x;++j)
			scanf("%d%d",&t,&v),
			E[i].push_back(mp(t,v));
	}
}
int main()
{
	in_put();ans=P[1];
	for(Low=L[1]-m;Low<=L[1];++Low)
		memset(F,-1,sizeof F),Up=Low+m,ans=std::min(ans,dfs(1));
	printf("%d\n",ans);
}