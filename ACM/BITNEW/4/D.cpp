#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e5+5;
    struct Genshin
    {
        int t,a;
        void input()
        {
            cin>>t>>a;
        }
        bool operator <(Genshin _)const
        {
            return _.a*(2*t+1)<a*(2*_.t+1);
        }
    }P[M];
    int n;
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            P[i].input();
        sort(P+1,P+n+1);
        int t=0;
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            t+=P[i].t;
            ans+=1ll*P[i].a*(t+i-1);
            t+=P[i].t;
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
