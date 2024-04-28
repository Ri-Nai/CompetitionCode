#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,tot;
    typedef pair<int,int> Pr;
    map<Pr,int>mp;
    vector<int>E[N];
    int gcd(int a,int b)
    {
        if(b<0)return gcd(a,-b);
        return b?gcd(b,a%b):a;
    }
    void solve()
    {
        cin>>n;
        tot=0;
        mp.clear();
        for(int i=1;i<=n;++i)
        {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2)swap(x1,x2),swap(y1,y2);
            if(x1==x2 and y1>y2)swap(y1,y2);
            int a=x2-x1,b=y2-y1;
            int g=gcd(a,b);
            a/=g,b/=g;
            if(!mp[{a,b}])mp[{a,b}]=++tot;
            ll t=1ll*a*y1-1ll*b*x1;
            E[mp[{a,b}]].push_back(t);
        }
        ll ans=1ll*n*(n-1)/2;
        for(int i=1;i<=tot;++i)
        {
            sort(E[i].begin(),E[i].end());
            // cout<<i<<' '<<E[i].size()<<'\n';
            for(int j=0;j<E[i].size();++j)
            {
                int k=j;
                while(k<E[i].size() and E[i][j]==E[i][k])++k;
                int cnt=k-j;
                // cout<<cnt<<"***\n";
                ans-=cnt*(E[i].size()-j-cnt);
                j=k-1;
            }
            E[i].clear();
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
