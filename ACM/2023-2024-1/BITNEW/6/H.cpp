#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=2e5+5,mod=1e9+7;
    int fac[N],inv[N],pow[N];
    int Pow(int x,int p)
    {
        int res=1;
        for(;p;p>>=1)
        {
            if(p&1)res=1ll*res*x%mod;
            x=1ll*x*x%mod;
        }
        return res;
    }
    int C(int n,int m)
    {
        return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    void solve()
    {
        cin>>n>>m;
        fac[0]=1;
        pow[0]=1;
        for(int i=1;i<=2*n;++i)
            fac[i]=1ll*fac[i-1]*i%mod,pow[i]=2ll*pow[i-1]%mod;
        inv[2*n]=Pow(fac[2*n],mod-2);
        for(int i=2*n-1;~i;--i)
            inv[i]=1ll*inv[i+1]*(i+1)%mod;
        int ans=0;
        for(int i=0;i<=m;++i)
        {
            int now=1ll*fac[2*n-i]*pow[i]%mod*C(m,i)%mod;
            if(i&1)ans=(ans+mod-now)%mod;
            else ans=(ans+now)%mod;
        }
        cout<<ans<<'\n';
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
/*

*/
