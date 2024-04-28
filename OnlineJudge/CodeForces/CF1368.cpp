#include<bits/stdc++.h>
using namespace std;
namespace T
{
    void Solve()
    {
        string s="codeforces";
        long long n,t=1;
        int k=1;
        cin>>n;
        if(n==1)
        {
            puts("codeforces");
            return;
        }
        while(t<n)
        {
            ++k;
            t=(long long)pow(k,10);
        }
        t=(long long)pow(k-1,10);
        for(int i=0;i<10;++i)
        {
            int x=k-1;
            if(t<n)t=t/(k-1)*k,++x;
            while(x--)putchar(s[i]);
        }
        puts("");
    }
}
int main()
{
    T::Solve();
}

