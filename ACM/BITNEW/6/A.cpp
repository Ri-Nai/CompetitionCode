#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int mod=1e9+7;
    int Qpow(int x,int p)
    {
        int res=1;
        while(p)
        {
            if(p&1)res=1ll*res*x%mod;
            p>>=1;
            x=1ll*x*x%mod;
        }
        return res;
    }
    void solve()
    {
        int n;
        int sum=0;
        int n1=0,n2=0;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x==1)++n2;
            else ++n1;
            sum=(sum+y)%mod;
        }
        if(n1==n)End("-1");
        cout<<1ll*sum*Qpow(n2,mod-2)%mod;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    T::solve();

}
/**
E=p1*(E+x1)+p2*x2
n2 E1=sum1+sum2;
*/
