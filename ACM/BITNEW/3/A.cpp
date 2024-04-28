#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        int n,p;
        cin>>n>>p;
        ll res=1,x;
        while(n--)
        {
            cin>>x;x%=p;
            res=res*x%p;
        }
        cout<<res;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
