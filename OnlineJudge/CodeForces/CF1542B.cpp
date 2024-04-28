#include<bits/stdc++.h>
using namespace std;
namespace T
{
    void solve()
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a==1)puts((n-1)%b==0?"Yes":"No");
        else
        {
            long long now=1;
            while(now<=n)
            {
                if((n-now)%b==0)
                {
                    puts("Yes");
                    return;
                }
                now*=a;
            }
            puts("No");
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
