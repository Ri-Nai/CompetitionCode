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
        int a,b;
        cin>>a>>b;
        cout<<a/b<<'\n';
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::Solve();
}
