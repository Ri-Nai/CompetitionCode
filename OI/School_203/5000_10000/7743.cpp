#include<bits/stdc++.h>
using namespace std;
#define EOR(i,u) for(int i=head[u],v;v=to[i];i=nxt[i])
const int N=5e5+5,M=N<<1;
typedef long long LL;
int n,k,num[N];
int W[M],to[M],head[N],nxt[M],tot;
LL mx[N],mmx[N],len[N],ans[N];
void Add(int u,int v,int w)
{
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;
    W[tot]=w;
}
int rd()
{
    int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
    while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return f?-t:t;
}
void dfs(int u,int f)//???????????
{
    EOR(i,u)if(v^f)
    {
        dfs(v,u);
        num[u]+=num[v];
        if(!num[v])continue;
        LL tmp=mx[v]+W[i];ans[1]+=W[i]<<1;
        if(tmp>mx[u])mmx[u]=mx[u],mx[u]=tmp;
        else if(tmp>mmx[u])mmx[u]=tmp;
    }
}
void ddfs(int u,int f)
{
    EOR(i,u)if(v^f)
    {
        LL now=max(len[u],mmx[u]);
        if(mx[v]+W[i]!=mx[u])
            now=max(now,mx[u]);
        now+=W[i];
        if(num[1]==num[v])now=0;
        len[v]=now;
        ddfs(v,u);
    }
}
void _dfs(int u,int f)
{
    EOR(i,u)if(v^f)
    {
        ans[v]=ans[u];
        // Rn_1(ans[u]);
        if(num[v]==num[1])ans[v]-=W[i]<<1;
        if(!num[v])ans[v]+=W[i]<<1;
        _dfs(v,u);
    }
}
int main()
{
    n=rd();k=rd();
    for(int i=1,u,v,w;i<n;++i)
        u=rd(),v=rd(),Add(u,v,w=rd()),Add(v,u,w);
    for(int i=1;i<=k;++i)++num[rd()];
    dfs(1,0);ddfs(1,0);_dfs(1,0);
    for(int i=1;i<=n;++i)printf("%lld\n",ans[i]-max(len[i],mx[i]));
}
