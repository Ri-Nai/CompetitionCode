#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int head[maxn],to[maxn],nxt[maxn],tot;
int n,Q,que[maxn],mark[maxn],f[maxn],fa[maxn],cnt[maxn],ans[maxn],num;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];f[v]=u;
	to[tot]=v;head[u]=tot;
}
void dfs(int u)
{
	if(!cnt[u])fa[u]=fa[f[u]];else fa[u]=u;
	for(int i=head[u];i;i=nxt[i])dfs(to[i]);
}
int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
int main()
{
	scanf("%d%d",&n,&Q);char tmp[2];
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(u,v);
	cnt[1]=1;
	for(int i=1;i<=Q;++i)
	{
		scanf("%s%d",tmp,&que[i]);
		mark[i]=(tmp[0]=='C'?1:0);
		if(mark[i])++cnt[que[i]];
	}dfs(1);
	for(int i=Q;i;--i)
		if(mark[i])
		{
			--cnt[que[i]];
			if(!cnt[que[i]])fa[que[i]]=find(f[que[i]]);
		}
		else ans[++num]=find(que[i]);
	while(num)printf("%d\n",ans[num--]);
}