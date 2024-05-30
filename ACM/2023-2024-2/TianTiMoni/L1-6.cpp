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
    void Solve()
    {
        string s;
        getline(cin,s);
        for(int i=0;i+1<s.size();++i)
        {
            if(islower(s[i]))
            {
                if(!isalpha(s[i+1]) or s[i+1]!=toupper(s[i]) and s[i+1]!=s[i]-1)
                    return puts("N"),void();
            }
            if(isupper(s[i]))
            {
                if(!isalpha(s[i+1]) or s[i+1]!=tolower(s[i]) and s[i+1]!=s[i]+1)
                    return puts("N"),void();
            }
        }
        puts("Y");
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
