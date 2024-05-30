#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    struct Pr
    {
        int x,y;
        bool operator <(Pr _)const
        {
            if(x==_.x)return y<_.y;
            return x>_.x;
        }
    }P[N];
    int n,k;
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>P[i].y;
        for(int i=1;i<=n;++i)cin>>P[i].x;
        sort(P+1,P+n+1);
        ll ans1=0,ans2=0;
        for(int i=1;i<=k;++i)
            ans1+=P[i].y,ans2+=P[i].x;
        cout<<ans1<<' '<<ans2<<'\n';
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
