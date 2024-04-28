#include<bits/stdc++.h>
using namespace std;
namespace Solve
{
    const int M=3e5+5;
    int n,m,L[M],R[M],l[M],r[M];
    char S[M];
    void Main()
    {
        scanf("%d%d",&n,&m);
        scanf("%s",S+1);
        r[1]=1,l[n]=n;
        set<pair<int,int> >T;
        for(int i=2;i<=n;++i)
            r[i]=S[i]=='1'?r[i-1]:i;
        for(int i=n-1;i>=1;--i)
            l[i]=S[i+1]=='0'?l[i+1]:i;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            T.insert(pair<int,int>(l[x],r[y]));
        }
        for(int i=1;i<=n;++i)
            printf("**%d %d\n",l[i],r[i]);
        printf("%d\n",T.size());
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)Solve::Main();
}
