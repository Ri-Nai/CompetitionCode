#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=N<<1;
typedef long long LL;
int tot,head[N],to[M],W[M],nxt[M];
int n,m,is[N];
LL mx[N],mmx[N],mmmx[N],ans;
void Add(int u,int v,int w)
{
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;
    W[tot]=w;
}
void work(int u,LL now,int v)
{
    if(now>mx[u])mmmx[u]=mmx[u],mmx[u]=mx[u],mx[u]=now,is[u]=v;
    else if(now>mmx[u])mmmx[u]=mmx[u],mmx[u]=now;
    else if(now>mmmx[u])mmmx[u]=now;
}
void dfs(int u,int f)
{
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];if(v==f)continue;
        dfs(v,u);LL now=mx[v]+W[i];
        work(u,now,v);
    }
}
void _dfs(int u,int f,LL now)
{
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];if(v==f)continue;
        LL res=(v==is[u]?mmx[u]:mx[u])+W[i];
        _dfs(v,u,max(res,now+W[i]));
    }
    work(u,now,-1);
    ans=max(ans,mx[u]+mmmx[u]+mmx[u]*2);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int u,v,w;m--;)scanf("%d%d%d",&u,&v,&w),Add(u,v,w),Add(v,u,w);
    dfs(1,0);_dfs(1,0,0);printf("%lld\n",ans);
}
/*
mx 从u伸出去的最长链,mmx 次长链

*/
