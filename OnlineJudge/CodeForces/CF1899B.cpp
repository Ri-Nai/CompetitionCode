#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1.5e5+5;
    int n;
    ll A[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i],A[i]+=A[i-1];
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            if(n%i)continue;
            ll mn=1e18,mx=-1e18;
            for(int j=i;j<=n;j+=i)
            {
                ll now=A[j]-A[j-i];
                if(now>mx)mx=now;
                if(now<mn)mn=now;
            }
            if(mx-mn>ans)ans=mx-mn;
        }
        cout<<ans<<'\n';
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
