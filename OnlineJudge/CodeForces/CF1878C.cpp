#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        ll n,k,x;
        cin>>n>>k>>x;
        ll MAX=k*(n+n-k+1)>>1;
        ll Min=k*(k+1)>>1;
        if(MAX<x or x<Min)End("NO");
        else End("YES");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
