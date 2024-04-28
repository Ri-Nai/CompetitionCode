#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=105;
    int n;
    struct DS
    {
        int D,S;
        void input()
        {
            scanf("%d%d",&D,&S);
        }
        bool operator <(const DS &T)const
        {
            return D<T.D;
        }
    }A[M];
    void solve()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)A[i].input();
        sort(A+1,A+n+1);
        int ans=1e9+5;
        for(int i=1;i<=n;++i)
            ans=min(ans,A[i].D+(A[i].S-1)/2);
        printf("%d\n",ans);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
