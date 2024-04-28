#include<bits/stdc++.h>
using namespace std;
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
const int N=1e5+5;
int head[N],nxt[N<<1],to[N<<1],tot;
int n,m,RT=1,fa[N],top[N],sz[N],son[N],dep[N],L[N],R[N],Re[N],num;
int A[N],mn[N<<2],lazy[N<<2];
inline void Add(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;head[u]=tot;
}
void dfs(int u)
{
    sz[u]=1;son[u]=0;dep[u]=dep[fa[u]]+1;
    for(int i=head[u];i;i=nxt[i])
    {
        int &v=to[i];
        dfs(v);sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void _dfs(int u,int tp)
{
    top[u]=tp;L[u]=++num;Re[num]=u;
    if(son[u])_dfs(son[u],tp);
    for(int i=head[u];i;i=nxt[i])
        if(to[i]!=son[u])_dfs(to[i],to[i]);
    R[u]=num;
}
inline void Up(int p){mn[p]=min(mn[p<<1],mn[p<<1|1]);}
void build(int L=1,int R=n,int p=1)
{
    if(L==R){mn[p]=A[Re[L]];return;}
    int mid=L+R>>1;
    build(Lson);build(Rson);Up(p);
}
void updata(int x,int y,int L=1,int R=n,int p=1)
{
    if(L==R){mn[p]=y;return;}
    int mid=L+R>>1;
    if(x<=mid)updata(x,y,Lson);
    else updata(x,y,Rson);
    Up(p);
}
int query(int l,int r,int L=1,int R=n,int p=1)
{
    if(L==l&&r==R)return mn[p];
    int mid=L+R>>1;
    if(r<=mid)return query(l,r,Lson);
    else if(l>mid)return query(l,r,Rson);
    else return min(query(l,mid,Lson),query(mid+1,r,Rson));
}
int Get(int u)
{
    if(u==RT)return query(1,n);
    if(L[RT]<=L[u]||R[u]<L[RT])return query(L[u],R[u]);
    int v=RT;while(top[fa[v]]^top[u])v=top[fa[v]];
    if(fa[v]!=u)v=son[u];
    int res=1e9;
    if(L[v]-1>=1)res=query(1,L[v]-1);
    if(R[v]+1<=n)res=min(res,query(R[v]+1,n));
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&fa[i],&A[i]);
        if(fa[i]!=0)Add(fa[i],i);
    }
    dfs(RT);_dfs(RT,RT);build();
    while(m--)
    {
        int u,w;char s[2];
        scanf("%s",s);
        if(s[0]=='E')scanf("%d",&RT);
        if(s[0]=='V')scanf("%d%d",&u,&w),updata(L[u],w);
        if(s[0]=='Q')scanf("%d",&u),printf("%d\n",Get(u));
    }
}