#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e6+5,P=998244353;
    void solve()
    {
        int n;
        cin>>n;
        if(n==1)End(1);
        if(n==2)End(2);
        int x1=1,x2=2,t;
        for(int i=3;i<=n;++i)
            t=x1,x1=x2,x2=(t+x2)%P;
        cout<<x2<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
