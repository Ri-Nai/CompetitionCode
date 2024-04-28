#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n,m;
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    int check(int x)
    {
        int p=0;
        while(x!=1)
        {
            if(x&1)return -1;
            x>>=1;++p;
        }
        return p;
    }
    ll calc(int x,int y)
    {
        int p=0;
        ll ans=0;
        while(x)
        {
            if(x&1)ans+=((1ll<<y-p)-1)*(1ll<<p);
            x>>=1;++p;
        }
        // cout<<y<<"AAA\n";
        return ans;
    }
    void solve()
    {
        cin>>n>>m;
        n-=n/m*m;
        int t=gcd(n,m);
        int p=check(m/t);
        if(!~p)End(-1);
        if(n==0)End(0);
        // p=check(m);
        n/=t;m/=t;
        End(calc(n,p)*t);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
