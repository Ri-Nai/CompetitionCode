#include<bits/stdc++.h>
using namespace std;
namespace T
{
    void solve()
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a<b)swap(a,b);
        int ans=ceil((double)(a-b)/c/2);
        printf("%d\n",ans);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
