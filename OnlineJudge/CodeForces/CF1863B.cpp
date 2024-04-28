#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=1e5+5;
    int A[M],id[M],n;
    void solve()
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]),id[A[i]]=i;
        for(int i=1;i<n;++i)
            if(id[i]>id[i+1])++ans;
        printf("%d\n",ans);
    }
}
int main()
{
    int t;cin>>t;
    while(t--)T::solve();
}
