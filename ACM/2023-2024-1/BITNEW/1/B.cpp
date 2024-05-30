#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    ll gcd(ll a,ll b)
    {
        return b?gcd(b,a%b):a;
    }
    ll lcm(ll a,ll b)
    {
        return a/gcd(a,b)*b;
    }
    void solve()
    {
        ll a,b,q;
        cin>>a>>b>>q;
        ll t=lcm(a,b);
        if(b>a)swap(a,b);
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            ll l1=l/t;
            ll l2=r/t;
            ll res=0;
            if(l1*t+a-1>=l)
                res+=l1*t+a-l;
            if(l2*t+a-1>=r)
                res-=l2*t+a-r-1;
            res+=(l2-l1)*a;
            cout<<r-l+1-res<<' ';
        }
        cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
        T::solve();

}
