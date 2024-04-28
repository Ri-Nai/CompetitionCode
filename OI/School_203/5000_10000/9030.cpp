#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e6+5;
#define ToMin(x,y) ((x>(y))&&(x=(y)))
#define EOR(i,u) for(int i=head[u],v;v=to[i];i=nxt[i])
int nxt[M],to[M],in[N],head[N],tot;
int n,m,stk[N],top;bool is[N],mark[N],vis[N];
pair<int,int>ans[M];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	++in[to[head[u]=tot]=v];
}
void dfs(int u,int f)
{
	EOR(i,u)if(v!=f&&mark[v])
	{
		if(!f)ans[++top]=make_pair(u,v);
		vis[v]=1;dfs(v,u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for(int i=1;i<=n;++i)if(in[i]==1)is[i]=stk[++top]=i;
	while(top)
	{
		int u=stk[top--];mark[u]=1;//不在环上
		EOR(i,u)if(--in[v]==1)stk[++top]=v;
	}
	for(int i=1;i<=n;++i)if(!mark[i])dfs(i,0);//环上的第一个
	for(int i=1;i<=n;++i)if(is[i]&&!vis[i])//叶子节点
		ans[++top]=make_pair(i,to[head[i]]);
	printf("%d\n",top);sort(ans+1,ans+top+1);
	for(int i=1;i<=top;++i)printf("%d %d\n",ans[i].first,ans[i].second);
}