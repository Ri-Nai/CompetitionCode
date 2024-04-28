#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=2e5+5;
    int n;
    int A[M],pre1[M],pre2[M];
    void solve()
    {
        scanf("%d",&n);
        pre1[1]=pre2[1]=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]);
        for(int i=2;i<=n;++i)
        {
            pre2[i]=pre2[i-1]+(A[i]>=A[i-1]);
            pre1[i]=pre1[i-1]+(A[i]<=A[i-1]);
        }
        pre1[n+1]=pre1[n];
        int ans=pre1[n];
        for(int i=1;i<=n;++i)
            ans=min(ans,1+pre2[i]+pre1[n]-pre1[i+1]);
        printf("%d\n",ans);
    }
}
int main()
{
    int t;cin>>t;
    while(t--)T::solve();
}
