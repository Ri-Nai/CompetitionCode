#include<bits/stdc++.h>
using namespace std;
namespace T
{
    int n,m;
    void solve()
    {
        cin>>n>>m;

        if(m==1)
        {
            for(int i=0;i<=n;++i)
                cout<<"0\n";
            return;
        }
        if(n+1>=m)cout<<m<<'\n';
        else cout<<n+1<<'\n';
        for(int i=0,x=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                cout<<(j+m-x)%m<<' ';
            x=(x+1)%(m-1);
            cout<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    T::solve();

}
