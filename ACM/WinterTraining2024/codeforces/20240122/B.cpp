#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    void solve()
    {
        double ans=0;
        // cin>>n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            ans+=pow(0.5,x-1)*-1+2;
        }
        // cout<<ans<<'\n';
        printf("%.4f\n",ans);
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
