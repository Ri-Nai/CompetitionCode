#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e5+5;
    int n,x;
    int A[M];
    double calc(int k)
    {
        return log(k+1)*k;
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            // cin>>A[i];
            scanf("%d",&A[i]);
        cin>>x;
        sort(A+1,A+n+1);
        double ans=0;
        int p=lower_bound(A+1,A+n+1,x)-A;
        for(int i=1;i<p;++i)
        {
            ans+=calc(A[i]-A[i-1]);
            // cout<<ans<<'\n';
        }
        // cout<<p<<'\n';
        ans+=calc(x-A[p-1]);
        // cout<<ans<<'\n';
        printf("%.7f\n",ans);

    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
