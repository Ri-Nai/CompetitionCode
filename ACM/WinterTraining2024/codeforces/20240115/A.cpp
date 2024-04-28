#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    const int N=30;
    int A[N],B[N];
    void solve()
    {
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)cin>>B[i];
        for(int i=2;i<=n;++i)
        {
            if(abs(A[i]-A[i-1])+abs(B[i]-B[i-1])>=
                abs(B[i]-A[i-1])+abs(A[i]-B[i-1]))
                swap(A[i],B[i]);
            ans+=abs(A[i]-A[i-1])+abs(B[i]-B[i-1]);
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
