#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    const int mod=998244353;
    const int N=105;
    int fac[N],inv[N];
    int Qpow(int x,int p)
    {
        int res=1;
        for(;p;p>>=1,x=1ll*x*x%mod)
            if(x&1)res=1ll*res*x%mod;
        return res;
    }
    void pre()
    {
        fac[0]=1;
        for(int i=1;i<N;++i)fac[i]=1ll*i*fac[i-1]%mod;
        inv[N-1]=Qpow(fac[N-1],mod-2);
        for(int i=N-2;i>=0;--i)inv[i]=1ll*(i+1)*inv[i+1]%mod;
    }
    int C(int n,int m)
    {
        if(m>n)return 0;
        return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
    }
    int f[2][N];
    void Solve()
    {
        pre();
        int n,m,x,k;
        cin>>n>>m>>x>>k;
        for(int i=1;i<=n;++i)
        {
            f[1][i]=1ll*C(x,i);
        }
    }
}
int main()
{
    T::Solve();
}
