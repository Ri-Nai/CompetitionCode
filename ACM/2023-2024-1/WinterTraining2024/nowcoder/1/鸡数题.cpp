#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    const int mod=1e9+7;
    int qpow(int x,int p)
    {
        int res=1;
        for(;p;p>>=1,x=1ll*x*x%mod)
            if(p&1)res=1ll*res*x%mod;
        return res;
    }
    void solve()
    {
        int n=rd(),m=rd();
        vector<int>fac(m+1);
        vector<int>inv(m+1);
        fac[0]=1;
        for(int i=1;i<=m;++i)fac[i]=1ll*fac[i-1]*i%mod;
        inv[m]=qpow(fac[m],mod-2);
        for(int i=m-1;i>=0;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
        int ans=0,flag=1;
        for(int i=0;i<=m;++i)
        {
            ans=(ans+1ll*flag*fac[m]*inv[m-i]%mod*inv[i]%mod*qpow(m-i,n)%mod+mod)%mod;
            flag=-flag;
        }
        cout<<1ll*inv[m]*ans%mod;

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
