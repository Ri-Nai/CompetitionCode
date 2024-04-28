#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e4+10;
int head[N],to[N<<1],nxt[N<<1],tot;
int top[N],fa[N],son[N],id[N],dep[N],siz[N],num,n,m,k;
LL C[N],A[N];
void Adde(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;head[u]=tot;
}
void dfs(int u,int f)
{
    dep[u]=dep[f]+1;son[u]=0;fa[u]=f;siz[u]=1;
    for(int i=head[u];~i;i=nxt[i])
    {
        int v=to[i];if(v==fa[u])continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v])
            son[u]=v;
    }
}
void _dfs(int u,int tp)
{
    top[u]=tp;id[u]=++num;
    if(son[u])_dfs(son[u],tp);
    for(int i=head[u];~i;i=nxt[i])
        if(to[i]!=fa[u]&&son[u]!=to[i])_dfs(to[i],to[i]);
}
void Add(int x,LL y){while(x<=n)C[x]+=y,x+=x&-x;}
LL Sum(int x){LL res=0;while(x)res+=C[x],x^=x&-x;return res;}
void update(int l,int r,LL w)
{
    Add(l,w);Add(r+1,-w);
}
void Adds(int u,int v,LL w)
{
    while(top[u]^top[v])
    {
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(id[top[u]],id[u],w);u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    update(id[u],id[v],w);
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
    	memset(C,0,sizeof C);memset(head,-1,sizeof head);tot=num=0;
        for(int i=1;i<=n;++i)scanf("%lld",&A[i]);
        while(m--){int x,y;scanf("%d%d",&x,&y);Adde(x,y);Adde(y,x);}
        dfs(1,1);_dfs(1,1);
        for(int i=1;i<=n;++i)Add(id[i],A[i]),Add(id[i]+1,-A[i]);
        while(k--)
        {
            char s[4];int x,y;LL z;scanf("%s",s);
            if(s[0]=='I'||s[0]=='D')
                scanf("%d%d%d",&x,&y,&z),Adds(x,y,s[0]=='I'?z:-z);
            else
                scanf("%d",&x),printf("%lld\n",Sum(id[x]));
        }
    }
}

/*projekt Red*/