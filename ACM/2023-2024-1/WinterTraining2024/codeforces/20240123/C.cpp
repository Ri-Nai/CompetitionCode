#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void solve()
    {
        ll n;int m;
        cin>>m>>n;
        ll ans=0;
        bool flag=0;
        for(int i=m-1;i>=2;--i)
        {
            ll now=1ll<<i;
            if(now&n)
            {
                if(!flag)flag=1,ans+=now-1;
                else ans+=now;
            }
            else ans+=now;
        }
        if(m>=2)
        {
            if(!flag)ans+=!(n&3)+3;
            else ans+=4;
        }
        else ans+=(n&1)+1;
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
