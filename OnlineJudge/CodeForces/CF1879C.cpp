#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=3e5+5;
    const int P=998244353;
    char s[M];
    int n;
    ll f[M],inv[M];

    ll qpow(ll n,int p)
    {
        ll res=1;
        while(p)
        {
            if(p&1)res=res*n%P;
            n=n*n%P;p>>=1;
        }
        return res;
    }
    void init()
    {
        f[0]=1;
        for(int i=1;i<M;++i)
            f[i]=f[i-1]*i%P;
        inv[M-1]=qpow(f[M-1],P-2);
        for(int i=M-2;i>=0;--i)inv[i]=inv[i+1]*(i+1)%P;
    }
    ll C(int n,int m)
    {
        if(m>n)return 0;
        return f[n]*inv[m]%P*inv[n-m]%P;
    }
    void solve()
    {
        cin>>s+1;
        n=strlen(s+1);
        ll res=1;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while(j+1<=n and s[i]==s[j+1])++j;
            ans+=j-i;
            res=res*(j-i+1)%P;
            i=j;
        }
        cout<<ans<<' '<<f[ans]*res%P<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T::init();
    int t;cin>>t;while(t--)
    T::solve();

}
