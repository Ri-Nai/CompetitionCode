#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int M=5e6+5;
    bool vis[M];
    int cnt[M],dp[M];
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=m;++i)
            vis[i]=cnt[i]=0,dp[i]=1e9;
        int ans=1e9,mn=1e9,mx=m;
        for(int i=1;i<=n;++i)
        {
            int x;cin>>x;
            vis[x]=1;
            mn=min(mn,x);
        }
        for(int i=m;i>=1;--i)//枚举当前的下限
        {
            dp[i]=i;
            if(vis[i])++cnt[i];
            for(ll j=1ll*i*i;j<=m;j+=i)//枚举可以被修改的数
            {
                if(vis[j])--cnt[dp[j]];
                dp[j]=min(dp[j],dp[j/i]);
                if(vis[j])++cnt[dp[j]];
            }
            if(i<=mn)
            {
                while(!cnt[mx])--mx;
                ans=min(ans,mx-i);
            }
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
