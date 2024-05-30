#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;ll p;
    int cnt;
    int get(ll x)
    {
        if(p&1)return x&1;
        x%=(p+1);
        if(x==p)
        {
            cnt^=1;
            return 1;
        }
        return x&1;
    }
    void solve()
    {
        cin>>n>>p;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ll x;cin>>x;
            ans^=get(x);
        }
        if(cnt or ans)End("GOOD");
        else End("BAD");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
