#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    const int M=3e5+5;
    int n,k,A[M],B[M],id[M];
    bool cmp(int x,int y)
    {
        return B[x]==B[y]?x<y:B[x]>B[y];
    }
    void Main()
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)id[i]=i,scanf("%d",&A[i]),B[i]=(A[i]-1)%k+1;
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=n;++i)printf("%d ",id[i]);
        puts("");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
