#include<bits/stdc++.h>
const int N=2e5+10;
using namespace std;
typedef long long LL;
#pragma GCC opimize(2)
#define cmp(a)(((a)<=(r))&&((a)>=(l)))
#define EOR(i,u)for(register int i=head[u];i;i=nxt[i])
#define FOR(i,a,b)for(register int i=a,i##_=b;i<=i##_;++i)
int rd()
{
    int t=0,c;
    do c=getchar();while(c<48||c>57);
    while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
struct node
{
    int pos,id;
    bool operator <(const node&_)const
    {
        return pos<_.pos;
    }
}E[N];
int n,Q,S,head[N],nxt[N],sz[N],blk[N];
LL sum[N],lz[N],Ad[N],Ct[N],A[N]; 
void Down(int u)
{
    sum[u]=0;
    EOR(i,u)
    {
        if(~lz[u])A[E[i].id]=lz[u];
        A[E[i].id]+=1ll*(E[i].pos-1)*Ct[u]+Ad[u];
        sum[u]+=A[E[i].id];
    }
    lz[u]=-1,Ad[u]=Ct[u]=0;
}
LL LQR(LL l,LL r){return (r-l+1)*(l+r)/2;}
void Up(int u){sum[u]=0;EOR(i,u)sum[u]+=A[E[i].id];}
int Get(int x){--x;int u=1;while(sz[u]<=x)x-=sz[u++];return u;}
void Build()
{
    sort(E+1,E+n+1);
    FOR(i,0,S)sz[i]=head[i]=0,lz[i]=-1;
    FOR(i,1,n)
    {
        int u=i/S+1;
        nxt[i]=head[u];
        E[i].pos=++sz[u];
        head[u]=i;
    }
    FOR(i,1,S)blk[i]=blk[i-1]+sz[i],Up(i);
}
void Rebuild()
{
    FOR(i,1,S)
    {
        sz[i]+=sz[i-1];Down(i);
        EOR(j,i)E[j].pos+=sz[i-1];
    }
    Build();
}
void Insert(int p,int x)
{
    int u=p<=n?Get(p):S;
    Down(u),p-=blk[u-1];
    EOR(i,u)if(E[i].pos>=p)++E[i].pos;
    A[++n]=x,E[n]=(node){p,n},nxt[n]=head[u],head[u]=n;
    ++sz[u],sum[u]+=x;
    if(sz[u]>S*2.4)Rebuild();
    FOR(i,1,S)blk[i]=blk[i-1]+sz[i];
}
void Set(int l,int r,int x)
{
    int u=Get(l),v=Get(r);
    if(u==v)
    {
        Down(u);
        EOR(i,u)if(cmp(blk[u-1]+E[i].pos))A[E[i].id]=x;
        return Up(u);
    }
    Down(u);Down(v);
    sum[u]=sum[v]=0;
    EOR(i,u)
    {
        if(blk[u-1]+E[i].pos>=l)A[E[i].id]=x;
        sum[u]+=A[E[i].id];
    }
    EOR(i,v)
    {
        if(blk[v-1]+E[i].pos<=r)A[E[i].id]=x;
        sum[v]+=A[E[i].id];
    }
    FOR(i,u+1,v-1)lz[i]=x,Ct[i]=Ad[i]=0,sum[i]=1ll*x*sz[i];
}
void Add(int l,int r,int x)
{
    int u=Get(l),v=Get(r);
    if(u==v)
    {
        Down(u);
        EOR(i,u)if(cmp(blk[u-1]+E[i].pos))
            A[E[i].id]+=1ll*(blk[u-1]+E[i].pos-l+1)*x;
        return Up(u);
    }
    Down(u);Down(v);
    sum[u]=sum[v]=0;
    EOR(i,u)
    {
        if(blk[u-1]+E[i].pos>=l)A[E[i].id]+=1ll*(blk[u-1]+E[i].pos-l+1)*x;
        sum[u]+=A[E[i].id];
    }
    EOR(i,v)
    {
        if(blk[v-1]+E[i].pos<=r)A[E[i].id]+=1ll*(blk[v-1]+E[i].pos-l+1)*x;
        sum[v]+=A[E[i].id];
    }
    FOR(i,u+1,v-1){
        Ad[i]+=1ll*(blk[i-1]-l+2)*x,Ct[i]+=x;
        sum[i]+=LQR(blk[i-1]-l+2,blk[i]-l+1)*x;
    }
}
LL query(int l,int r)
{
    int u=Get(l),v=Get(r);
    LL now=0;
    Down(u);Down(v);
    if(u==v)
    {
        Down(u);
        EOR(i,u)if(cmp(blk[u-1]+E[i].pos))
            now+=A[E[i].id];
        return now;
    }
    Down(u);Down(v);
    EOR(i,u)if(blk[u-1]+E[i].pos>=l)now+=A[E[i].id];
    EOR(i,v)if(blk[v-1]+E[i].pos<=r)now+=A[E[i].id];
    FOR(i,u+1,v-1)now+=sum[i];
    return now;
}
int main()
{
    n=rd(),Q=rd();S=ceil(sqrt(n+Q));
    FOR(i,1,n)A[i]=rd(),E[i]=(node){i,i};
    Build();FOR(i,1,Q)
    {
        int op=rd(),l,r,x;
        if(op==1)l=rd(),r=rd(),x=rd(),Set(l,r,x);
        else if(op==2)l=rd(),r=rd(),x=rd(),Add(l,r,x);
        else if(op==3)l=rd(),x=rd(),Insert(l,x);
        else if(op==4)l=rd(),r=rd(),printf("%lld\n",query(l,r));
    }
}