#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    void Main()
    {
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            if(x==i)++cnt;
        }
        printf("%d\n",(cnt+1)/2);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
