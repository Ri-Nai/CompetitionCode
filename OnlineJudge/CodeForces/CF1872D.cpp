#include<bits/stdc++.h>
using namespace std;
namespace T
{
    int gcd(int x,int y)
    {
        return y?gcd(y,x%y):x;
    }
    void solve()
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        long long lcm=1ll*x/gcd(x,y)*y,ans=0;
        int a=n/x,b=n/y,c=n/lcm;
        a-=c,b-=c;
        ans=1ll*(n+n-a+1)*a/2-1ll*(1+b)*b/2;
        printf("%lld\n",ans);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
