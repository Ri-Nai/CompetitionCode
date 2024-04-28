#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
//
namespace T
{
    ll x;
    void solve()
    {
        cin>>x;
        vector<int>ans;
        int t=0;
        for(int i=60;i>=0;--i)
            if(x&1ll<<i){t=i;break;}
        for(int i=1;i<=t;++i)
            ans.push_back(i);
        for(int i=t-1;i>=0;--i)
            if(x&1ll<<i)ans.push_back(i+1);
        cout<<ans.size()<<'\n';
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
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
