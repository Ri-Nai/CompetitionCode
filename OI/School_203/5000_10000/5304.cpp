#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=N<<1;
int n,m,clr[N],dp[N][2];
int nxt[M],to[M],head[N],tot;
inline void Add(int u,int v)
{
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;
}
void dfs(int u,int f)
{
    if(u<=m)return dp[u][clr[u]^1]=0x3f3f3f3f3f,void();
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==f)continue;
        dfs(v,u);
        dp[u][0]+=min(dp[v][0],dp[v][1]+1);
        dp[u][1]+=min(dp[v][1],dp[v][0]+1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)scanf("%d",&clr[i]);
    for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
    dfs(m+1,0);printf("%d\n",min(dp[m+1][0],dp[m+1][1])+1);
}
/*
*/
