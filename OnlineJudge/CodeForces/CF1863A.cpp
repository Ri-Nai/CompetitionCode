#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=105;
    int n,a,q;
    char s[M];
    void solve()
    {
        scanf("%d%d%d",&n,&a,&q);
        scanf("%s",s+1);
        int flag1=0,flag2=0,b=a;
        if(a>=n)flag1=1;
        for(int i=1;i<=q;++i)
        {
            if(s[i]=='+')++a,++b;
            else --a;
            if(a>=n)flag1=1;
            if(b>=n)flag2=1;
        }
        if(flag1)puts("YES");
        else if(flag2)puts("MAYBE");
        else puts("NO");
    }
}
int main()
{
    int t;cin>>t;
    while(t--)T::solve();
}
