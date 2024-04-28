#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,q;
    const ll lim=1e18+5;
    const int N=1e5+4;
    map<ll,int>mp;
    ll num[N];
    int tot;
    ll len;
    void solve()
    {
        cin>>n>>q;
        mp.clear();
        len=tot=0;
        // cout<<"AAAA"<<'\n';
        for(int i=1;i<=n;++i)
        {
            int x,a;
            cin>>x>>a;
            if(len>=lim)continue;
            if(x==1)mp[++len]=a;
            else
            {
                num[++tot]=len;
                ++a;
                if(lim/a<len)len=lim;
                else len*=a;
            }
        }
        // num[++tot]=len;
        // cout<<tot<<'\n';
        for(int i=1;i<=q;++i)
        {
            ll k;cin>>k;
            for(int j=tot;~j;--j)
            {
                // cout<<num[j]<<'\n';
                if(mp[k])
                {
                    cout<<mp[k]<<" ";
                    break;
                }
                k=(k-1)%num[j]+1;
            }
        }
        cout<<'\n';
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
