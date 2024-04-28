#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n,e;
    int rnd(double t)
    {
        int x=t;
        // double t1=fabs(t-x);
        // double t2=fabs(t-x-1);
        // double t3=fabs(t-x+1);
        // // cout<<x<<' '<<t1<<' '<<t2<<' '<<t3<<'\n';
        // if(t1<=t2 and t1<=t3)return x;
        // if(t2<=t1 and t2<=t3)return x+1;
        return x-1;
    }
    void solve()
    {
        cin>>n>>e;
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            int r;
            cin>>r;
            long double ang=2*asin(1.*e/2/r);
            // cout<<4*asin(1)/ang<<'\n';
            long double rr=4*asin(1)/ang;
            int num=rr;
            if(e==r)num=6;
            if(e==2*r)num=2;
            if(e>2*r)num=1;
            // cout<<num<<'\n';
            // if(e==2*r)num=2;
            ans+=num;
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
