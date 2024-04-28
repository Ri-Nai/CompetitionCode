#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#define pb push_back
#define pr std::pair<int,int>
#define mp std::make_pair
const int maxn=1e5+5;
int n,m,A[maxn],M[2][maxn],ans;
std::vector<int>E[2][maxn];
void bfs(int k)
{
	std::queue<pr>Q;//id value
	if(k)Q.push(mp(n,A[n]));
	else Q.push(mp(1,A[1]));
	while(!Q.empty())
	{
		int u=Q.front().first,
			w=Q.front().second;
		Q.pop();
		for(int i=0;i<E[k][u].size();++i)
		{
			int v=E[k][u][i],val=A[v];
			if(k)
			{
				if(w>val)val=w;
				if(val>M[k][v])M[k][v]=val,Q.push(mp(v,val));
			}
			else
			{
				if(w<val)val=w;
				if(val<M[k][v])M[k][v]=val,Q.push(mp(v,val));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		E[0][u].pb(v);E[1][v].pb(u);
		if(w==2)
		E[0][v].pb(u),E[1][u].pb(v);
	}
	memset(M[0],0x3f,sizeof  M[0]);bfs(0);
	memset(M[1],-0x3f,sizeof M[1]);bfs(1);
	for(int i=1;i<=n;++i)
		if(M[1][i]-M[0][i]>ans)
			ans=M[1][i]-M[0][i];
	printf("%d\n",ans);
}