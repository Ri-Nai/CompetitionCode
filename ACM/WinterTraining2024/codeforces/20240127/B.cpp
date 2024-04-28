#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e6+5;
    ll A[N];
    void solve()
    {
        int k;
        ll n,m,x;
        cin>>k;
        for(int i=1;i<=k;++i)cin>>A[i];
        cin>>n>>m>>x;
        for(int i=1;i<=k;++i)
        {
            // A[i]=(A[i]-1)%m+1;
            // A[i]%=m;
            A[i]+=A[i-1];
        }
        x%=m;
        ll res=x+n/k*A[k]+A[n%k];
        // cout<<res<<'\n';
        res/=m;
        cout<<n-res<<'\n';
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
