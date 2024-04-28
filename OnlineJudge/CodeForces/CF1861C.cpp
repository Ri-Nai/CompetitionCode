#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=2e5+5;
    char s[M];
    void solve()
    {
        scanf("%s",s);
        int now=0,mn=M,lst=1,n=strlen(s);
        for(int i=0;i<n;++i)
        {
            char c=s[i];
            if(c=='+')
                ++now;
            else if(c=='-')
            {
                --now;
                if(now<lst)lst=now;
            }
            else if(c=='1')
            {
                if(now>=mn)return puts("NO"),void();
                lst=now;
            }
            else
            {
                if(now==1)return puts("NO"),void();
                if(now<=lst)return puts("NO"),void();
                mn=min(now,mn);
            }
            if(now<mn)mn=M;
        }
        puts("YES");
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
