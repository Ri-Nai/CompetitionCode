#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    const int N=2e5+5;
    int A[N];
    ll D[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=2;i<=n;++i)D[i]=A[i]-A[i-1];
        for(int i=2;i<=n;++i)D[i]+=D[i-2];
        set<ll>S;
        for(int i=1;i<=n;i+=2)
        {
            if(S.find(D[i])!=S.end())
            {
                cout<<"YES\n";
                return;
            }
            S.insert(-A[i]+D[i]);
            S.insert(D[i]);
        }
        S.clear();
        for(int i=0;i<=n;i+=2)
        {
            if(S.find(D[i])!=S.end())
            {
                cout<<"YES\n";
                return;
            }
            S.insert(-A[i]+D[i]);
            S.insert(D[i]);
        }
        cout<<"NO\n";
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
