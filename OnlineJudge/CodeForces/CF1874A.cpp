#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=105;
    int a,b,n;
    int A[M];
    void solve()
    {
        cin>>a>>b>>n;
        ll ans=0;
        ans+=b-1;
        for(int i=1;i<=n;++i)cin>>A[i],ans+=min(A[i],a-1);
        ++ans;
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
