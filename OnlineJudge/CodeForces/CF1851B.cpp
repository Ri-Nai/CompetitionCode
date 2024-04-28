#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    const int M=2e5+10;
    int n,A[M],B[M];
    void Main()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
        sort(A+1,A+n+1);
        for(int i=1;i<=n;++i)
            if(A[i]%2!=B[i]%2)
            {
                puts("NO");
                return;
            }
        puts("YES");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
