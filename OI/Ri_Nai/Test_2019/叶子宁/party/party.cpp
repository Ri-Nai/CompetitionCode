#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define F
const int maxn=1e5+5;
std::vector<int> frd[maxn],son[maxn];
std::priority_queue<int,std::vector<int>,std::greater<int> > Q;
int father[maxn],n,m,ans;
bool is[maxn],mark[maxn];
void pre()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		frd[u].push_back(v);
		frd[v].push_back(u);
	}
}
void dfs(int t)
{
	for(int i=0;i<frd[t].size();++i)
		if(!is[frd[t][i]])
		{
			is[frd[t][i]]=1;
			dfs(frd[t][i]);
		}
}
void travel()
{
	while(!Q.empty())
	{
		int now=Q.top();
		Q.pop();
		printf("%d ",now);
		for(int i=0;i<frd[now].size();++i)
			if(!mark[frd[now][i]])
				mark[frd[now][i]]=1,
				Q.push(frd[now][i]);
	}
}
void solv()
{	
	for(int i=1;i<=n;++i)
		if(!is[i])
		{
			is[i]=1;
			father[++ans]=i;
			dfs(i);
		}
}
void print()
{
	printf("%d\n",ans);
	memset(is,0,sizeof is);
	for(int i=1;i<=ans;++i)
	{
		mark[father[i]]=1;
		Q.push(father[i]);
	}
	travel();
}
void solve()
{
	pre();
	solv();
	print();
}
int main()
{
	#ifndef F
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
