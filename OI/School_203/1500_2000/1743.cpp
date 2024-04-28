#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int nxt[maxn],T[maxn],W[maxn],to[maxn],head[maxn],tot;
int n,A[maxn];double Need[maxn];
void Add(int u,int v,int w,int t)
{
	nxt[++tot]=head[u];
	W[tot]=w;T[tot]=t;
	to[tot]=v;head[u]=tot;
}
void dfs(int u)
{
	if(~A[u]){Need[u]=A[u];return ;}
	double mx=0;
	for(int i=head[u];i;i=nxt[i])
	{
		dfs(to[i]);
		double tmp=Need[to[i]]*100.0/W[i];
		if(T[i])tmp=min(tmp,sqrt(Need[to[i]])*100.0/W[i]);
		mx=max(tmp,mx);
	}
	Need[u]=mx;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v,w,t;i<n;++i)
		scanf("%d%d%d%d",&u,&v,&w,&t),Add(u,v,w,t);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	dfs(1);printf("%.4f\n",Need[1]);
}