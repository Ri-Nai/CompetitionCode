#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n;
    int L[N],R[N],id[N];
    vector<pair<int,int> >E;
    void solve()
    {
        cin>>n;
        for(int i=1,a,b,c,d;i<=n;++i)
        {
            cin>>a>>b>>c>>d;
            E.push_back({a,1});
            E.push_back({c,-1});
        }
        sort(E.begin(),E.end());
        int last=0,now=0;
        int ans=0;
        for(auto [x,y]:E)
        {
            if(y==1)if(!now++)last=x;
            if(y==-1)if(!--now)ans+=x-last;
        }
        cout<<ans<<'\n';
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
