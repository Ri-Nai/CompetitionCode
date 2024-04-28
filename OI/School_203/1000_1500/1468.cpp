#include<cstdio>
#include<vector>
#include<algorithm>
const int maxn=1e5+5;
long long diff[maxn],ans[maxn],sum;
int n,Q,U[maxn],L[maxn],R[maxn],Delta[maxn];
std::vector<int>E[maxn],D[maxn];
void Add(int id,int dep,int mark)
{
	for(int i=0;i<D[id].size();++i)
	{
		int j=D[id][i];
		if(dep<=R[j])
		{
			int k=std::max(L[j],dep);
			diff[k]+=mark*Delta[j];
			diff[R[j]+1]-=mark*Delta[j];
		}
	}
}
void dfs(int id,int dep)
{
	Add(id,dep,1);ans[id]=sum+=diff[dep];
	for(int i=0;i<E[id].size();++i)
		dfs(E[id][i],dep+1);
	sum-=diff[dep];Add(id,dep,-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=2,x;i<=n;++i)scanf("%d",&x),E[x].push_back(i);
	scanf("%d",&Q);
	for(int i=1;i<=Q;++i)
		scanf("%d%d%d%d",&U[i],&L[i],&R[i],&Delta[i]),
		D[U[i]].push_back(i);
	dfs(1,1);
	int MOD=1000000007,MAGIC=12347;
	long long Hash=0;
	for(int i=1;i<=n;++i)
		Hash=(Hash*MAGIC+ans[i])%MOD;
	printf("%lld\n",Hash);
}