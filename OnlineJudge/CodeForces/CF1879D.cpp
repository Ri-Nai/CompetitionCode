#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=3e5+5;
    const int P=998244353;
    int n,A[N];
    ll cnt[2],sum[2];
    void solve()
    {
        cin>>n;
        ll res=0;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=0;i<32;++i)
        {
            cnt[0]=cnt[1]=sum[0]=sum[1]=0;
            int now=0,k=1<<i;
            for(int j=1;j<=n;++j)
            {
                bool t=A[j]&k;
                sum[now]+=j-1;
                sum[now]%=P;
                ++cnt[now];
                now^=t;
                // if(t)cout<<i<<' '<<j<<' '<<now;
                // if(i<2)cout<<cnt[now^1]<<' '<<sum[now^1]<<'\n';
                res=(res+1ll*k*(cnt[now^1]*j%P-sum[now^1]+P)%P)%P;
            }
        }
        cout<<res<<'\n';


    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
