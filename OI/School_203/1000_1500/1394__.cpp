#include<cstdio>
#include<vector>
#include<cstring>
const int maxn=1e5+5;
std::vector<int>V[maxn];
int n,m,mark[maxn];
bool flag=1;
void dfs(int id,int color)
{
	mark[id]=color;
	for(int i=0;i<V[id].size();++i)
	{
		int to=V[id][i];
		if(~mark[to])
		{
			if(mark[to]==mark[id])flag=0;
		}
		else dfs(to,color^1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(mark,-1,sizeof mark);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),
		V[a].push_back(b),
		V[b].push_back(a);
	for(int i=1;i<=n;++i)
		if(mark[i]==-1)dfs(i,1);
	if(flag)puts("it's your own problem");
	else puts("there are must be something wrong");
}