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
    const int mod=998244353;
    int Qpow(int n,int p)
    {
        int res=1,x=n;
        for(;p;x=1ll*x*x%mod,p>>=1)
            if(p&1)res=1ll*res*x%mod;
        return res;
    }
    void solve()
    {
        map<int,int>cnt;
        int n=rd(),m=rd();
        int t=n,q=sqrt(n);
        for(int i=2;i<=q;++i)
        {
            while(t%i==0)
            {
                ++cnt[i];
                t/=i;
            }
        }
        if(t!=1)++cnt[t];
        int ans=1;
        for(auto [x,y]:cnt)
        {
            // cout<<x<<' '<<y<<'\n';
            ans=1ll*ans*(Qpow(y+1,m)-Qpow(y,m))%mod;
            ans=(ans+mod)%mod;
        }
        printf("%d\n",ans);
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
