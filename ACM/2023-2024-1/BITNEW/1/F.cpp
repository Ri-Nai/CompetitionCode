#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=1e6+5;
    int n,to[152];
    char s[N];
    void solve()
    {
        cin>>n>>(s+1);
        to['e']=1;
        to['o']=2;
        to['w']=3;
        int ans=1;
        for(int i=2;i<=n;++i)
        {
            if(to[s[i]]<=to[s[i-1]])
                ++ans;
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
