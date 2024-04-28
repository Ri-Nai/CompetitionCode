#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,A[N];
    map<int,int>cnt;
    void solve()
    {
        cin>>n;
        cnt.clear();
        ll ans=0;
        for(int i=1;i<=n;++i)
            cin>>A[i],++cnt[A[i]];
        for(auto t:cnt)
            ans+=1ll*t.second*(t.second-1)/2;
        ans+=1ll*cnt[1]*cnt[2];
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
