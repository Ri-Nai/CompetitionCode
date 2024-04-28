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
    bool check(int x)
    {
        if(x==1)return 0;
        for(int i=2;i<x;++i)
            if(x%i==0)return 0;
        return 1;
    }
    void Solve()
    {
        int n;cin>>n;
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            int now=1<<i;
            --now;
            if(check(now))flag=1,cout<<now<<'\n';
        }
        if(!flag)cout<<"None\n";
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    T::Solve();
}
