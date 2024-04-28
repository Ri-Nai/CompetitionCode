#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"inline","Ofast")
using namespace std;
const int N=5e4+5;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
#define sqr(x) (1ll*(x)*(x))
int fa[N],n,k,C[N],num;
bool ans[35],dp[35][N];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
struct City
{
    int x,y,k;
    void read(){scanf("%d%d%d",&x,&y,&k);k%=::k;}
    bool operator <(const City &_)const{return x<_.x;}
    double Dis(const City &_)const{return sqrt(sqr(x-_.x)+sqr(y-_.y));}
}A[N];
struct Edge
{
    int u,v;double w;
    bool operator <(const Edge &_)const{return w<_.w;}
}B[N],E[N<<6];
void Merge(int u,int v,double w)
{
    u=find(u);v=find(v);
    //Rn_3(u,v,w);
    if(u==v)return;fa[v]=u;
    memset(ans,0,sizeof ans);
    FOR(i,0,k-1)FOR(j,0,k-1)
        ans[i]|=dp[i][u],ans[j]|=dp[j][v],
        ans[(i+j)%k]|=dp[i][u]&dp[j][v];
    if(ans[0])printf("%.3f\n",w),exit(0);
    FOR(i,0,k-1)dp[i][u]=ans[i];
}
int main()
{
    scanf("%d%d",&n,&k);
    FOR(i,1,n)A[i].read(),fa[i]=i;
    sort(A+1,A+n+1);double D=1e9;
    FOR(i,1,n)C[i]=A[i].x,dp[A[i].k][i]=1;
    FOR(i,1,n)
    {
        int L=lower_bound(C+1,C+n+1,C[i]-D-1e-5)-C,
            R=upper_bound(C+1,C+n+1,C[i]+D+1e-5)-C-1;
        double d;int tot=0;
        for(int j=L;j<=R;++j)
            if(i!=j&&(d=A[i].Dis(A[j]))<D+1e-5)
                B[++tot]=(Edge){i,j,d};
        sort(B+1,B+tot+1);
        if(tot>=k)D=B[tot=k].w;
        while(tot)E[++num]=B[tot--];
    }
    sort(E+1,E+num+1);
    FOR(i,1,num)Merge(E[i].u,E[i].v,E[i].w);
}