#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int N=1e5+5;
    int A[N],sum[N],n,m;
    char s[N];
    void solve()
    {
        int all=0,now=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]),sum[i]=sum[i-1]^A[i];
        all=sum[n];
        scanf("%s",s+1);
        for(int i=1;i<=n;++i)
            if(s[i]=='1')now^=A[i];
        scanf("%d",&m);
        while(m--)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                now^=sum[r]^sum[l-1];
            }
            else
            {
                int y;
                scanf("%d",&y);
                if(y)printf("%d\n",now);
                else printf("%d\n",all^now);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
