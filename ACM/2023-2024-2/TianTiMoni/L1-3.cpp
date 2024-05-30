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
        int n,m,k;
        string s;
        cin>>n>>s>>m>>k;
        if(k==n)cout<<"mei you mai "<<s<<" de\n";
        else if(k==m)cout<<"kan dao le mai "<<s<<" de\n";
        else cout<<"wang le zhao mai "<<s<<" de\n";
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::Solve();
}
