#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    const int mod=998244353;
    int fac[N],inv[N];
    int pow(int x,int p)
    {
        int res=1;
        for(;p;p>>=1)
        {
            if(p&1)res=1ll*res*x%mod;
            x=1ll*x*x%mod;
        }
        return res;
    }
    void pre()
    {
        fac[0]=1;
        for(int i=1;i<N;++i)
            fac[i]=1ll*fac[i-1]*i%mod;
        inv[N-1]=pow(fac[N-1],mod-2);
        for(int i=N-2;i>=0;--i)
            inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    int C(int m,int n)
    {
        // cout<<fac[m]<<' '<<inv[m-n]<<' '<<inv[n]<<'\n';
        return 1ll*fac[m]*inv[m-n]%mod*inv[n]%mod;
    }
    void solve()
    {
        vector<int>V(3,0);
        for(int i=0;i<3;++i)cin>>V[i];
        int ans=1;
        for(int i=0;i<3;++i)
        {
            for(int j=i+1;j<3;++j)
            {
                int res=0;
                int x=V[i],y=V[j];
                if(x>y)swap(x,y);
                for(int k=0;k<=x;++k)
                    res=(res+1ll*C(y,k)*C(x,k)%mod*fac[k]%mod)%mod;
                ans=1ll*ans*res%mod;
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
    T::pre();
    int t;cin>>t;while(t--)
    T::solve();

}
