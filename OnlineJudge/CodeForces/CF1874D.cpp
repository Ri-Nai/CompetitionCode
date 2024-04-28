#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=5e3+5;
    int n,A[M];
    map<int,int>mp;
    ll dp[M];
    void solve()
    {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i],++mp[A[i]];
        int now=-1;
        for(int i=0;i<=n+2;++i)
            if(!mp[i])
            {
                now=i;
                break;
            }
        for(int i=now;~i;--i)dp[i]=1e18;
        dp[now]=0;
        for(int i=now-1;~i;--i)
            for(int j=i+1;j<=now;++j)
                dp[i]=min(dp[i],dp[j]+(mp[i]-1)*j+i);
        cout<<dp[0]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
