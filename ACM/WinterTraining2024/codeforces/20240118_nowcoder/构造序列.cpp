#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=14;
    ll S[N];
    void solve()
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>S[i];
            cout<<S[i]-S[i-1]<<" \n"[i==n];
        }
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
