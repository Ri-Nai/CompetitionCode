#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    ll n,x;
    ll gcd(ll a,ll b)
    {
        return b?gcd(b,a%b):a;
    }
    void solve()
    {
        cin>>n>>x;
        ll g=gcd(n,x);
        n/=g,x/=g;
        ll l=1,r=n>>1,res=-1;
        while(l<=r)
        {
            ll mid=l+r>>1;
            if(mid*(n-mid)<=x)
                res=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<res*g<<' '<<n*g-res*g<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
