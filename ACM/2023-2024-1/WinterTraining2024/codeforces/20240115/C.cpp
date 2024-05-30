#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    double Pow(double x,int p)
    {
        double res=1;
        for(;p;p>>=1)
        {
            if(p&1)res=res*x;
            x=x*x;
        }
        return res;
    }
    int n,k;
    double Get(int n)
    {
        // return (4.*(1-Pow(1./k,n/2-1))/(1-1./k)-1.*k*(2*n-1)+3/Pow(1./k,n/2-1))/(1-k);
        if(n&1)
            return n+(4.*(1./k-Pow(1./k,n-1>>1)/(1-1./k))
            -(2*n-5)+3.*Pow(1./k,n-1>>1))/(1-k);
        // else
            // return n+(4.*(1./k-Pow(1./k,n-2>>1)/(1-1./k))
            // -(2*n-3)+5*Pow(1./k,n-2>>1))/(1-k)+Pow(1./k,n>>1);
            // return (3-1.*(k+1)*n)/(1-k)+1/(Pow(k,n>>1)*(1-k))+(Pow(k,n>>1)-k)/(Pow(k,n>>1)*(k-1));
    }
    void solve()
    {
        cin>>n>>k;
        // printf("%.8lf\n",Get(n));
        // if(n&1)printf("%.8lf\n",Get(n));
        // else
        if(k==1)
        {
            printf("%lld\n",1ll*n*(n+1)/2);
        }
        else
        {
            double res=0;
            for(int i=n;i>=1;--i)
            {
                double now=i*1.0*Pow(1./k,(n-i+1)/2);
                if(now<1e-8)break;
                res+=now;
            }
            printf("%.8lf\n",res);
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
/*

*/
