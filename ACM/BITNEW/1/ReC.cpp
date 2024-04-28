#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e6+5;
    int n,a,b,c,d;
    int cnt1[M],cnt2[M];
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    inline ll lcm(int a,int b)
    {
        return 1ll*a/gcd(a,b)*b;
    }
    void solve()
    {
        cin>>a>>d>>n;
        ll ans=0;
        for(int i=1;i<=n;++i)
            cnt1[i]=cnt2[i]=0;
        // cout<<"AAA"<<'\n';
        for(int i=1;i<=n;++i)
        {
            ++cnt1[gcd(a,i)];
            ll t=lcm(i,d);
            if(t<=n)++cnt2[t];
        }
        for(int i=1;i<=n;++i)
            ans+=1ll*cnt1[i]*cnt2[i];
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
