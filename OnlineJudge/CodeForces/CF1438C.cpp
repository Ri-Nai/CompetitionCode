#include<bits/stdc++.h>
using namespace std;
namespace T
{
    int n,m;
    void solve()
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1,x;j<=m;++j)
                scanf("%d",&x),printf("%d%c",x%2!=(i+j)%2?x:x+1," \n"[j==m]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
