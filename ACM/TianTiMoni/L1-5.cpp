#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    bool Find(string s)
    {
        for(int i=0;i+2<s.size();++i)
            if(s[i]=='P' and s[i+1]=='T' and s[i+2]=='A')
                return 1;
        return 0;
    }
    void Solve()
    {
        string s;
        getline(cin,s);
        if(s[s.size()-1]!='?')
            puts("enen");
        else if(Find(s))
            puts("Yes!");
        else puts("No.");

    }
}
int main()
{
    // ios::sync_with_stdio(0);
    int t;cin>>t;
    getchar();
    while(t--)
    T::Solve();
}
