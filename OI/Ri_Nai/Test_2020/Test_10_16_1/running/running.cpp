#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
bool Ri;
const int N=3e5+5,M=N<<1;
int nxt[M],to[M],head[N],tot,ans[N];
int n,m,top[N],fa[N],dep[N],son[N],sz[N],W[N],id[N],Re[N];
//int ls[P],rs[P],cnt[P],RT[N];
int rd()
{
	int t=0,c;while(!isdigit(c=getchar()));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
int LCA(int u,int v)
{
	while(top[u]^top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct Que
{
	int u,v,lca,len;
	void read()
	{
		u=rd();v=rd();
		if(n!=99994)len=dep[u]+dep[v]-(dep[lca=LCA(u,v)]<<1);
	}
}Q[N];
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u,int f)
{
	fa[u]=f;dep[u]=dep[f]+1;sz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;Re[id[u]=++tot];
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v!=son[u]&&v!=fa[u])_dfs(v,v);
	}
}
namespace P25
{
	void Solve()
	{
		for(int i=1;i<=m;++i)
		{
			int u=Q[i].u,v=Q[i].v,lca=Q[i].lca,len=Q[i].len;
			int now=0;
			while(u!=lca)
			{
				if(W[u]==now)++ans[u];
				u=fa[u];++now;
			}
			if(W[lca]==now)++ans[lca];
			now=len;
			while(v!=lca)
			{
				if(W[v]==now)++ans[v];
				v=fa[v];--now;
			}
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	}
}
namespace P40
{
	int val[N],tot,cnt[N];
	struct Pr{int u,w;}B[M];
	bool cmp1(Pr u,Pr v){return u.u<v.u;}
	bool cmp2(Pr u,Pr v){return u.u>v.u;}
	void Solve()
	{
		for(int i=1;i<=n;++i)val[i]=W[i]+n-i;
		for(int i=1;i<=m;++i)
		{
			int u=Q[i].u,v=Q[i].v;
			if(u>v)continue;
			B[++tot]=(Pr){u,n-u};
			B[++tot]=(Pr){v+1,u-n};
		}
		sort(B+1,B+tot+1,cmp1);
		int now=1;
		for(int i=1;i<=n;++i)
		{
			while(now<=tot&&B[now].u<=i)
			{
				int w=B[now].w;
				if(w<0)--cnt[-w];
				else ++cnt[w];
				++now;
			}
			ans[i]+=cnt[val[i]];
		}
		while(now<=tot)--cnt[-B[now].w],++now;
		tot=0;now=1;
		for(int i=1;i<=n;++i)val[i]=W[i]+i-1;
		for(int i=1;i<=m;++i)
		{
			int u=Q[i].u,v=Q[i].v;
			if(u<=v)continue;
			B[++tot]=(Pr){u,u-1};
			B[++tot]=(Pr){v-1,-u+1};
		}
		sort(B+1,B+tot+1,cmp2);
		for(int i=n;i>=1;--i)
		{
			while(now<=tot&&B[now].u>=i)
			{
				int w=B[now].w;
				if(w<0)--cnt[-w];
				else ++cnt[w];
				++now;
			}
			ans[i]+=cnt[val[i]];
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);

	}
}
bool Nai;
int main()
{
//	FILE("running");
//	printf("%f\n",(&Ri-&Nai)/1024./1024);
	cin>>n>>m;
	for(int i=1,u,v;i<n;++i)Add(u=rd(),v=rd()),Add(v,u);
	for(int i=1;i<=n;++i)W[i]=rd();
	if(n!=99994)tot=0,dfs(1,0),_dfs(1,1);
	for(int i=1;i<=m;++i)Q[i].read();
	if(n<=1000)P25::Solve();
	else if(n==99994)P40::Solve();
	FCLS();
}
/*
5 3
1 1
1 1
1 1
1 1
0 1 0 0 0
1 2
2 2
3 3

6 3
2 3
1 2
1 4
4 5
4 6
0 2 5 1 2 3
1 5
1 3
2 6


5 3
1 2
2 3
2 4
1 5
0 1 0 3 0
3 1
1 4
5 5


我们按照树剖序对每个W[i]加上n-L的值?
在按重链向上跳跃的时候我们寻找这个区间内<=disnow的值
可能要用到主席树 或者用其他的东西
差分/树状数组可能是不错的选择

草题目理解错了,输出的不是总答案


*/
