#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=2e5+5;
    ll A[N],B[N],D;
    bool check(ll x,ll y)
    {
        return x<=y and -x<=y;
    }
    void solve()
    {
        cin>>n>>m>>D;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=m;++i)cin>>B[i];
        sort(A+1,A+n+1);
        sort(B+1,B+m+1);
        ll ans=-1;
        for(int i=1;i<=n;++i)
        {
            int p=upper_bound(B+1,B+m+1,A[i]+D)-B;
            int q=lower_bound(B+1,B+m+1,A[i]-D)-B;
            // cout<<p<<' '<<q<<'\n';
            if(p!=q)ans=max(ans,B[p-1]+A[i]);
        }
        cout<<ans<<'\n';
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
