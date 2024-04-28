#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=1e4+5;
    double X,Y,S;
    double x[N],y[N],w[N];
    void solve()
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i]>>y[i]>>w[i];
            X+=w[i]*x[i];Y+=w[i]*y[i];
            S+=w[i];
        }
        X/=S;
        Y/=S;
        double ans=0;
        for(int i=1;i<=n;++i)
            ans+=w[i]*(fabs(X-x[i])+fabs(Y-y[i]));
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
