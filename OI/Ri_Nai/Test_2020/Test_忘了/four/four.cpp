#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=2005,M=5005,inf=0x3f3f3f3f;
bool Ri;
int n,m,nxt[M],head[N],to[M],tot,Q[N],L,R;
int dis[N][N],id[N][N],Re[N][N],ans;
struct pr
{
	int u,w;
	bool operator <(const pr &_)const
	{
		return w>_.w;
	}
};vector<pr>E[N];
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void bfs(int u)
{
	L=R=0;Q[++R]=u;
	id[u][u]=1;
	dis[u][1]=0;
	Re[u][1]=u;
	E[u].push_back((pr){u,0});
	while(L<R)
	{
		int v=Q[++L];
		for(int i=head[v],w;w=to[i];i=nxt[i])
			if(!id[u][w])
			{
				Q[id[u][w]=++R]=w;Re[u][R]=w;
				E[w].push_back((pr){u,dis[u][R]=dis[u][L]+1});
			}
	}
}
bool Nai;
int main()
{
	FILE("four");
	scanf("%d%d",&n,&m);
	for(int u,v;m--;)scanf("%d%d",&u,&v),Add(u,v);
	for(int i=1;i<=n;++i)bfs(i);
	for(int i=1;i<=n;++i)sort(E[i].begin(),E[i].end());
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==j)continue;
			int k=0,p=n;
			while(E[i][k].u==j)++k;
			while(Re[j][p]==i||Re[j][p]==E[i][k].u)--p;
			ans=max(ans,E[i][k].w+dis[j][p]+dis[i][id[i][j]]);
			k=0,p=n;
			while(Re[j][p]==i)--p;
			while(E[i][k].u==j||E[i][k].u==Re[j][p])++k;
			ans=max(ans,E[i][k].w+dis[j][p]+dis[i][id[i][j]]);
		}
	cout<<ans<<endl;
	FCLS();
}
/*
8 16
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

3 8
7 4
5 2
8 5
4 7
6 2
2 4
7 6

*/
