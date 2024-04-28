#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int N=205;
    int n,A[N];
    void main()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]);
        sort(A+1,A+n+1);
        if(A[1]==A[n])puts("-1");
        else
        {
            int l1=1,l2=0;
            for(;A[l1]!=A[n];++l1);
            --l1;l2=n-l1;
            printf("%d %d\n",l1,l2);
            for(int i=1;i<=l1;++i)
                printf("%d ",A[i]);
            puts("");
            for(int i=l1+1;i<=n;++i)
                printf("%d ",A[i]);
            puts("");

        }
    }
}
int main ()
{
    int t;scanf("%d",&t);
    while(t--)T::main();
}
