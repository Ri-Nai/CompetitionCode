#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=5e3+5;
    struct String
    {
        int n;
        char s[M];
        void input()
        {
            scanf("%s",s+1);
            n=strlen(s+1);
        }
    }A,B;
    bool judge(String A,String B)
    {
        for(int i=1;i<A.n;++i)
            if(A.s[i]==B.s[i] and A.s[i+1]==B.s[i+1]
                and A.s[i]=='0' and A.s[i+1]=='1')
                return 1;
        return 0;
    }
    void solve()
    {
        A.input();B.input();
        puts(judge(A,B)?"YES":"NO");
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
