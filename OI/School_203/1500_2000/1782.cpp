#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,nxt[N<<1],to[N<<1],id[N<<1],head[N],tot;
int U[N],V[N],mark[N];
void Add(int u,int v,int i)
{
	nxt[++tot]=head[u];id[tot]=i;
	to[tot]=v;head[u]=tot;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&U[i],&V[i]);
		Add(U[i],V[i],i);Add(V[i],U[i],i);
	}
	memset(mark,-1,sizeof mark);
	queue<int>Q;Q.push(1);mark[1]=1;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(~mark[v])continue;
			mark[v]=1-mark[u];
			Q.push(v);
		}
	}
	for(int i=1;i<n;++i)printf("%d\n",mark[V[i]]);
}