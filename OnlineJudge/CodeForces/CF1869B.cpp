#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace T
{
    const int M=2e5+5;
    int n,k,a,b;
    int X[M],Y[M];
    void solve()
    {
        cin>>n>>k>>a>>b;
        for(int i=1;i<=n;++i)
            cin>>X[i]>>Y[i];
        ll mn1=1e18,mn2=1e18;
        for(int i=1;i<=k;++i)
        {
            mn1=min(mn1,0ll+abs(X[i]-X[a])+abs(Y[i]-Y[a]));
            mn2=min(mn2,0ll+abs(X[i]-X[b])+abs(Y[i]-Y[b]));
        }
        cout<<min(mn1+mn2,0ll+abs(X[a]-X[b])+abs(Y[a]-Y[b]))<<'\n';
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
