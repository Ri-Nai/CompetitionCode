#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=5e4+5;
    int n,A[M],B[M],mn;
    void main()
    {
        scanf("%d",&n);mn=1e9+7;
        long long ans=0,res=0;
        for(int i=1;i<=n;++i)
        {
            int m;
            scanf("%d",&m);
            A[i]=B[i]=1e9+7;
            for(int j=1;j<=m;++j)
            {
                int x;
                scanf("%d",&x);
                if(x<A[i])B[i]=A[i],A[i]=x;
                else if(x<B[i])B[i]=x;
            }
            if(A[i]<mn)mn=A[i];
            res+=B[i];
        }
        for(int i=1;i<=n;++i)
            ans=max(res-B[i]+mn,ans);
        printf("%lld\n",ans);
    }
}
int main ()
{
    int t;scanf("%d",&t);
    while(t--)T::main();
}
