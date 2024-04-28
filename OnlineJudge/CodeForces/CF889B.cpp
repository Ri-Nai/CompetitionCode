#include<bits/stdc++.h>
using namespace std;
namespace Solve
{


    void Main()
    {
        long long n;
        scanf("%lld",&n);
        int ans=1;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(n%i!=0)
            {
                ans=i-1;
                flag=0;
                break;
            }
        }
        if(flag)ans=n;
        printf("%d\n",ans);

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
