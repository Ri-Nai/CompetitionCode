#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int ans[200];
namespace T
{
    const int N=1e5+5;
    int n,k,x,p0;
    int s[N],t[N],p[N];
    bool check(int u)
    {
        long double t0=(long double)x/s[u];
        // cout<<t0<<'*'<<'\n';
        for(int i=0;i<=k;++i)
        {
            int now=p[i]-t[i];
            // cout<<now<<'\n';
            if(t0-1e-6<=now)
            {
                if(i==k)return 1;
                t0-=t[i+1]-t[i];
                if(t0<0)return 1;
            }
        }
        return 0;
    }
    void solve()
    {
        cin>>n>>k>>x>>p0;
        for(int i=1;i<=n;++i)
            cin>>s[i];
        for(int i=1;i<=k;++i)cin>>t[i];
        for(int i=1;i<=k;++i)cin>>p[i];
        p[0]=p0;
        sort(s+1,s+n+1);
        int l=1,r=n,res=n+1;
        // cout<<check(1)<<' '<<check(2)<<' '<<check(3)<<'\n';
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid))
                res=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<n-res+1<<'\n';
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
