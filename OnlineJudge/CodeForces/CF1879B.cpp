#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=3e5+5;
    int n,A[M],B[M];
    void solve()
    {
        cin>>n;
        int mn1=1e9+5,mn2=1e9+5;
        ll sum1=0,sum2=0;
        for(int i=1;i<=n;++i)cin>>A[i],sum1+=A[i],mn1=min(mn1,A[i]);
        for(int i=1;i<=n;++i)cin>>B[i],sum2+=B[i],mn2=min(mn2,B[i]);
        cout<<min(sum1+1ll*n*mn2,sum2+1ll*n*mn1)<<'\n';

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
