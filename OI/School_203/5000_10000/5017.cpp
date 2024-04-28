#include<cstdio>
#include<cstring>
#define R register
const int N=55,M=2005,inf=0x3f3f3f3f;
int m,n,A[N],B[N],C[N],dp[55][105][M],f[M],ans[M];
int head[N],nxt[N],to[N],W[N],tot;
bool mark[N];
int read()
{
    int t=0,c;
    do c=getchar();while(c<48||c>57);
    while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
void ToMin(int &x,const int &y){y<x&&(x=y);}
void ToMax(int &x,const int &y){y>x&&(x=y);}
void Add(int u,int v,int w)
{
    nxt[++tot]=head[u];
    to[tot]=v;W[tot]=w;
    head[u]=tot;mark[v]=1;
}
void dfs(int u)
{
 
    if(!head[u])
    {
        ToMin(C[u],m/B[u]);
        for(R int i=0;i<=C[u];++i)
            for(R int j=i;j<=C[u];++j)
                dp[u][i][j*B[u]]=A[u]*(j-i);
        return ;
    }
    C[u]=inf;
    for(R int i=head[u];i;i=nxt[i])
    {
        dfs(to[i]);B[u]+=W[i]*B[to[i]];
        ToMin(C[u],C[to[i]]/W[i]);
    }
    ToMin(C[u],m/B[u]);
    for(R int i=0;i<=C[u];++i)
    {
        memset(f,0,sizeof f);
        for(R int j=head[u];j;j=nxt[j])
            for(R int k=m;~k;--k)
            {
                int tmp=-inf;
                for(R int l=k;~l;--l)
                    ToMax(tmp,f[k-l]+dp[to[j]][i*W[j]][l]);
                f[k]=tmp;
            }
        for(R int j=0;j<=i;++j)
            for(R int k=0;k<=m;++k)
                ToMax(dp[u][j][k],f[k]+A[u]*(i-j));
    }
}
int main()
{
    n=read();m=read();
    memset(dp,-inf,sizeof dp);
    for(R int i=1;i<=n;++i)
    {
        A[i]=read();char tmp[2];
        scanf("%s",tmp);
        if(tmp[0]=='A')
            for(int u,v,j=1,k=read();j<=k;++j)
                u=read(),v=read(),Add(i,u,v);
        else B[i]=read(),C[i]=read();
    }
    for(R int i=1;i<=n;++i)
    {
        if(mark[i])continue;dfs(i);
        for(R int j=m;j>=0;--j)
            for(R int k=0;k<=j;++k)
                ToMax(ans[j],ans[j-k]+dp[i][0][k]);
    }
    printf("%d\n",ans[m]);
 
}