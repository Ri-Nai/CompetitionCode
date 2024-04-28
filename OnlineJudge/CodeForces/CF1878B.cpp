#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    void solve()
    {
        int n;
        cin>>n;
        for(int i=n;i>=1;--i)
            cout<<(int)1e9-i<<' ';
        cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();
}
