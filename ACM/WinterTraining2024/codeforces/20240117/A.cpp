#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int ans[200];
namespace T
{
    void solve()
    {
        int k;
        cin>>k;
        cout<<ans[k]<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    for(int i=1;i<=6;++i)
            for(int j=i;j<=6;++j)
                ans[i+j]++;
    int t;cin>>t;while(t--)
    T::solve();

}
