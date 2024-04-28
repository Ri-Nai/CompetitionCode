#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m,Q,dis[N],vis[N];
int nxt[M],to[M],W[M],head[N],tot;
int rd()
{
    int t=0,c;while(!isdigit(c=getchar()));
    while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
void Add(int u,int v,int w)
{
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;W[tot]=w;
}
void SPFA()
{
    queue<int>Q;
    // Q.push(0);vis[0]=1;
    for(int i=1;i<=n;++i)Q.push(i),vis[i]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();vis[u]=0;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i],w=W[i];
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])Q.push(v),vis[v]=1;
            }
        }
    }
}
int main()
{
    n=rd();m=rd();Q=rd();
    for(int i=1;i<=n;++i)dis[i]=rd();
    for(int i=1,v,u;i<=Q;++i)
        u=rd(),v=rd(),Add(u,v,rd());
    // for(int i=1;i<=n;++i)Add(0,i,0);
    SPFA();
    for(int i=1;i<=n;++i)printf("%d\n",dis[i]);
}