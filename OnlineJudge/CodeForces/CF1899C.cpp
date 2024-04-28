#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,A[N];
    void solve()
    {
        cin>>n;
        ll ans=-1e18;
        ll now=0;
        for(int i=1;i<=n;++i)
        {
            cin>>A[i];
            if(i!=1 and abs(A[i])%2==abs(A[i-1])%2)now=0;
            // cout<<i<<' '<<A[i]<<' '<<A[i-1]<<' '<<now<<'\n';
            now+=A[i];
            if(now>ans)ans=now;
            if(now<0)now=0;
        }
        End(ans);
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
