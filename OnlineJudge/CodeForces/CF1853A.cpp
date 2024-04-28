#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int N=505;
    int n,A[N];
    void solve()
    {
        scanf("%d",&n);
        int mx=0,mn=1e9+3;
        for(int i=1,x;i<=n;++i)
        {
            scanf("%d",&x);
            if(i!=1)mn=min(x-mx,mn);
            mx=max(mx,x);
            // printf("%d----\n",mn);
        }
        if(mn<0)puts("0");
        else printf("%d\n",(mn)/2+1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
