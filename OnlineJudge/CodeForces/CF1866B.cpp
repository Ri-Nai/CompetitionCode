#include<bits/stdc++.h>
using namespace std;
const int P=998244353,M=1e5+5;
int n,m,A[M],X[M],B[M],Y[M],mark[M],t,ans=1;
inline void prod(int &x,int y)
{
    x=1ll*x*y%P;
}
int Pow(int x,int p)
{
    int res=1;
    while(p)
    {
        if(p&1)prod(res,x);
        prod(x,x);
        p>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    for(int i=1;i<=n;++i)scanf("%d",&X[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)scanf("%d",&B[i]);
    for(int i=1;i<=m;++i)scanf("%d",&Y[i]);
    for(int i=1,j=1;i<=n;++i)
    {
        while(j<=m and B[j]<A[i])++j;
        if(j<=m and A[i]==B[j])
        {
            X[i]-=Y[j];
            mark[j]=1;
            if(X[i]<0)return puts("0"),0;
        }
        if(X[i])++t;
    }
    for(int i=1;i<=m;++i)
        if(!mark[i])
            return puts("0"),0;
    printf("%d\n",Pow(2,t));
}
