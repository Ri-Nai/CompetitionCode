#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
const int maxn=5e4+5;
int n,F[maxn][21],dep[maxn],root[maxn],
mx,val[maxn],L[maxn],R[maxn],id[maxn];
bool vis[maxn];
std::vector<int>E[maxn];
int find(int x)
{
    return x!=root[x]?root[x]=find(root[x]):x;
}
void dfs(int now,int fa)
{
    F[now][0]=fa;
    dep[now]=dep[fa]+1;
    for(int i=0;i<E[now].size();++i)
        if(E[now][i]!=fa)dfs(E[now][i],now);
}
void Up(int &n,int step)
{
    for(int i=0;i<21;++i)
        if(step&(1<<i))
            n=F[n][i];
}
int LCA(int a,int b)
{
    if(dep[a]>dep[b])std::swap(a,b);
    Up(b,dep[b]-dep[a]);
    if(a==b)return a;
    for(int i=20;i>=0;--i)
        if(F[a][i]!=F[b][i])
            a=F[a][i],b=F[b][i];
    return F[a][0];
}
int dis(int a,int b)
{
    return dep[a]+dep[b]-dep[LCA(a,b)]*2+1;
}
void Union(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y)return;
    root[x]=y;
    int x1=L[x],y1=R[x],x2=L[y],y2=R[y];
    if(dis(x1,y1)>dis(L[y],R[y]))L[y]=x1,R[y]=y1;
    if(dis(x1,y2)>dis(L[y],R[y]))L[y]=x1,R[y]=y2;
    if(dis(x1,x2)>dis(L[y],R[y]))L[y]=x1,R[y]=x2;
    if(dis(x2,y1)>dis(L[y],R[y]))L[y]=x2,R[y]=y1;
    if(dis(y1,y2)>dis(L[y],R[y]))L[y]=y1,R[y]=y2;
}
bool cmp(int a,int b){return val[a]>val[b];}
main()
{   
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&val[i]),
        id[i]=root[i]=L[i]=R[i]=i;
    for(int i=1,u,v;i<n;++i)
        scanf("%lld%lld",&u,&v),
        E[u].push_back(v),
        E[v].push_back(u);
    std::sort(id+1,id+n+1,cmp);dfs(1,0);
    for(int i=1;i<=20;++i)
        for(int j=1;j<=n;++j)
            F[j][i]=F[F[j][i-1]][i-1];
    for(int i=1;i<=n;++i)
    {
        int now=id[i];vis[now]=1;
        for(int j=0;j<E[now].size();++j)
            if(vis[E[now][j]])Union(E[now][j],now);
        //printf("%lld %lld\n",val[now],dis(L[now],R[now]));
        mx=std::max(mx,1LL*val[now]*(dis(L[now],R[now])));
    }
    printf("%lld\n",mx);
}