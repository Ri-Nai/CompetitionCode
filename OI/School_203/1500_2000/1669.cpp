#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N],mark[N];
int n,m,k;
vector<int>E[N],to[N];
int bfs()
{
	queue<pair<int,int> >Q;
	Q.push(make_pair(1,1));
	while(!Q.empty())
	{
		int u=Q.front().first,step=Q.front().second;
		Q.pop();if(u==n)return step;
		for(int i=0;i<to[u].size();++i)
		{
			int &f=to[u][i];
			if(!mark[f])
			{
				mark[f]=1;
				for(int j=0;j<E[f].size();++j)
				{
					int &v=E[f][j];
					if(!vis[v]&&(vis[v]=1))
						Q.push(make_pair(v,step+1));
				}
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i)
	{
		for(int j=1,u;j<=k;++j)
		{
			scanf("%d",&u);
			to[u].push_back(i);
			E[i].push_back(u);
		}
	}
	printf("%d\n",bfs());
}