#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    int Abs(int x)
    {
        return x>0?x:-x;
    }
    void Main()
    {
        int cnt=0,n,m,k,H;
        scanf("%d%d%d%d",&n,&m,&k,&H);
        for(int i=1;i<=n;++i)
        {
            int now=0;
            scanf("%d",&now);
            int t=Abs(now-H);
            if(t and t<=(m-1)*k and t%k==0)
                ++cnt;
        }
        printf("%d\n",cnt);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
