#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int stk[N],fa[N],sz,ans[N],diff[N<<1],n,cir[N],top,K,in[N],to[N],head[N],nxt[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u,int rt)
{
	++ans[stk[++top]=u];
	int k=min(K-top+2,sz);//深度
	if(k>0)++diff[rt],--diff[rt+k];//贡献
	else --ans[stk[top-K-1]];//减去之前加上的贡献
	for(int i=head[u],v;v=to[i];i=nxt[i])
		dfs(v,rt),ans[u]+=ans[v];--top;
}
void solve(int u)
{
	for(int v=u;in[v];v=fa[v])in[cir[++sz]=v]=0;
	for(int i=0;i<=sz+sz;++i)diff[i]=0;
	for(int i=1;i<=sz;++i)dfs(cir[i],i);
	for(int i=1;i<=sz+sz;++i)diff[i]+=diff[i-1];
	for(int i=1;i<=sz;++i)ans[cir[i]]=diff[i]+diff[i+sz];//断环为链
}
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i)scanf("%d",&fa[i]),++in[fa[i]];
	for(int i=1;i<=n;++i)if(!in[i])stk[++top]=i;
	while(top)
	{
		int u=stk[top--],v=fa[u];
		if(!--in[v])stk[++top]=v;
	}
	for(int i=1;i<=n;++i)if(!in[i])Add(fa[i],i);
	for(int i=1;i<=n;++i)if(in[i])sz=0,solve(i);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
}