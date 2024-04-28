#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    const int M=2e5+10;
    int n,k,A[M];
    void Main()
    {
        int cnt1=0,t1=-1,cnt2=0,t2=-1;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d",&A[i]);
        for(int i=1;i<=n;++i)if(A[i]==A[1] and ++cnt1==k)t1=i;
        for(int i=n;i>=1;--i)if(A[i]==A[n] and ++cnt2==k)t2=i;
        if(~t1 and ~t2 and (t1<t2 or A[1]==A[n]))puts("YES");
        else puts("NO");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
