#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),k=rd();
        vector<int>E;
        for(int i=1;i<=n;++i)
            E.push_back(rd());
        const int mod=1e9+7;
        ll sum=0,now=0,res=0;
        auto Qpow=[&](ll x,int p)
        {
            ll res=1;
            for(;p;x=1ll*x*x%mod,p>>=1)
                if(p&1)res=1ll*res*x%mod;
            return res;
        };
        for(int x:E)
        {
            sum+=x;
            now+=x;
            if(now<0)now=0;
            if(now>res)res=now;
        }
        res%=mod;
        sum%=mod;
        sum+=1ll*(Qpow(2ll,k)-1)*res%mod;
        sum%=mod;
        sum+=mod;
        sum%=mod;
        printf("%lld\n",sum);
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();
}
