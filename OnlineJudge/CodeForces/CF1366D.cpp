#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int N=1e7+5,M=5e5+5;
    int n,m,A[M],B[M],P[N];
    void init()
    {
        for(int i=1;i<N;++i)P[i]=i;
        for(int i=2;i*i<N;++i)
            for(int j=i+i;j<N;j+=i)if(P[j]==j)P[j]=i;
    }
    void solve()
    {
        init();
        scanf("%d",&n);
        for(int i=1,x;i<=n;++i)
        {
            scanf("%d",&x);
            int t=P[x],y=x;
            while(x%t==0)x/=t;
            B[i]=x,A[i]=y/x;
            if(A[i]==B[i] or B[i]==1)A[i]=B[i]=-1;
        }
        for(int i=1;i<=n;++i)
            printf("%d%c",A[i]," \n"[i==n]);
        for(int i=1;i<=n;++i)
            printf("%d%c",B[i]," \n"[i==n]);
    }
}
int main()
{
    T::solve();
}
