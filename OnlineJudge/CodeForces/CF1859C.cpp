#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=255;
    int n;
    bool mark[M];
    void Solve()
    {
        scanf("%d",&n);
        int ans=0;
        for(int now=n*n;now>=1;--now)
        {
            int res=-now;
            for(int i=1;i<=n;++i)mark[i]=0;
            for(int i=n;i>=1;--i)
            {
                int x=now/i;
                if(x>n)x=n;
                while(x and mark[x])--x;
                if(!x)break;
                mark[x]=i;
                res+=x*i;
            }
            if(res>ans)
            {
                // for(int i=1;i<=n;++i)
                //     printf("%d ",mark[i]);
                // puts("");
                ans=max(res,ans);
            }
        }
        printf("%d\n",ans);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::Solve();
}
