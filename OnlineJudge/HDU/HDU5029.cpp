#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ls p<<1
#define rs p<<1|1
#define CLEAR(x) memset(x,0,sizeof x)
int n,m,top[N],fa[N],son[N],sz[N],id[N],dep[N],Re[N],num,ans[N];
int nxt[N<<1],head[N],to[N<<1],tot,sum[N<<2],mx[N<<2];
vector<int>C[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
void dfs(int u,int f)
{
	sz[u]=1;son[u]=0;dep[u]=dep[f]+1;fa[u]=f;
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void _dfs(int u,int tp)
{
	top[u]=tp;id[u]=++num;Re[num]=u;
	if(son[u])_dfs(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=son[u]&&to[i]!=fa[u])_dfs(to[i],to[i]);
}
inline void Add(int l,int r,int w)
{
	C[l].push_back(w);
	C[r+1].push_back(-w);
}
void change(int u,int v,int w)
{
	while(top[u]^top[v])
    {
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        Add(id[top[u]],id[u],w);u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    Add(id[u],id[v],w);
}
void updata(int x,int y,int L=1,int R=N-1,int p=1)
{
	if(L==R){sum[p]+=y;mx[p]=x;return;}
	int mid=L+R>>1;
	if(x<=mid)updata(x,y,L,mid,ls);
	else updata(x,y,mid+1,R,rs);
	if(sum[ls]>=sum[rs])mx[p]=mx[ls],sum[p]=sum[ls];
	else mx[p]=mx[rs],sum[p]=sum[rs];
}
int main()
{
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(int i=0;i<N;++i)C[i].clear();
		CLEAR(head);CLEAR(sum);CLEAR(mx);tot=num=0;
		for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
		dfs(1,0);_dfs(1,1);
		for(int i=1,u,v,w;i<=m;++i)scanf("%d%d%d",&u,&v,&w),change(u,v,w);
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<C[i].size();++j)
			{
				int k=C[i][j];
				updata(k<0?-k:k,k<0?-1:1);
			}
			ans[Re[i]]=mx[1];
		}
		for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	}
}