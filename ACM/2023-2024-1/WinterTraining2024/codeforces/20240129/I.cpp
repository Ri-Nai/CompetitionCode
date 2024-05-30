#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5,mod=1e9+7;
    int n;
    int A[N],fac[N],inv[N];
    int Qpow(int n,int p)
    {
        int res=1;
        for(int x=n;p;x=1ll*x*x%mod,p>>=1)
            if(p&1)res=1ll*res*x%mod;
        return res;
    }
    void Pre()
    {
        fac[0]=1;
        for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mod;
        inv[N-1]=Qpow(fac[N-1],mod-2);
        for(int i=N-2;i>=0;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    int A_(int &p,int m)
    {
        if(p<m)return 1;
        int n=p;
        p-=m;
        return 1ll*fac[n]*inv[n-m]%mod;
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        ll ans=1;
        int pre=1;
        int rest=0;
        if(A[1]!=0)End("0");
        for(int i=2;i<=n;++i)
        {
            if(A[i]<i-1 or A[i]>=n or A[i]<A[i-1])End("0");
            if(A[i]!=A[i-1])ans=2*ans*A_(rest,i-pre-1)%mod,rest+=A[i]-A[i-1]-1,pre=i;
        }
        ans=ans*fac[n-pre]%mod;
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    T::Pre();
    int t;cin>>t;while(t--)
    T::solve();

}
