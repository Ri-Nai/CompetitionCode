#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        ll n;
        cin>>n;
        if(n&1)End("-1");
        // else cout<<n/2<<'\n';
        while(n%2==0)n>>=1;
        cout<<n<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
