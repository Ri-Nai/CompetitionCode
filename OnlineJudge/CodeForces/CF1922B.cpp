#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=3e5+5;
    int cnt[N],n;
    long long ans,sum[N];
    void solve()
    {
        cin>>n;
        ans=0;
        for(int i=0;i<=n+1;++i)sum[i]=cnt[i]=0;
        for(int x,i=1;i<=n;++i)
            cin>>x,++cnt[x];
        for(int i=n;i>=0;--i)
            sum[i]=1ll*cnt[i]*(cnt[i]-1)/2,
            sum[i]+=sum[i+1];
        for(int i=0;i<=n;++i)
        {
            ans+=1ll*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
            ans+=1ll*cnt[i]*sum[i+1];
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
