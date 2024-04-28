#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=1e5+5;
    int A[M],n,k,mark[M];
    void solve()
    {
        scanf("%d%d",&n,&k);
        memset(mark,0,sizeof mark);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&A[i]);
            mark[A[i]]=1;
        }
        for(int i=0;i<=n;++i)
            if(!mark[i])A[0]=i;
        k%=(n+1);
        for(int i=1;i<=n;++i)
            printf("%d%c",A[(i-k+n+1)%(n+1)]," \n"[i==n]);
    }
}
int main()
{
    int t;cin>>t;
    while(t--)T::solve();
}
