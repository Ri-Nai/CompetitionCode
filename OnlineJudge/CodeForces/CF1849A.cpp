#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    int n,m,k;
    void Main()
    {
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",min(2*n-1,2*(m+k)+1));
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
