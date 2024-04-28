#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e6+5;
    int n,W,C,w[N];
    void solve()
    {
        cin>>n>>W>>C;
        for(int i=1;i<=n;++i)cin>>w[i];
        sort(w+1,w+n+1);
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            if(C-w[i]<0)End(ans);
            ans+=W-w[i];
            C-=w[i];
        }
        End(ans);
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
