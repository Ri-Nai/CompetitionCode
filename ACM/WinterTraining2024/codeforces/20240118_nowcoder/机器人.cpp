#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    ll k;
    string s;
    const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    int D[256],X,Y;
    ll get(int x,int y)
    {
        return (x+1)*1000000000ll+y;
    }
    map<ll,int>mark;
    int Cnt()
    {
        int res=0;
        for(int i=0;i<s.size();++i)
        {
            X+=dx[D[s[i]]];
            Y+=dy[D[s[i]]];
            ll now=get(X,Y);
            if(!mark[now])++res;
            mark[now]=1;
        }
        return res;
    }
    void solve()
    {
        D['R']=0;
        D['U']=1;
        D['L']=2;
        D['D']=3;
        cin>>s;
        cin>>k;
        mark[get(0,0)]=1;
        ll ans=1;
        for(ll i=1,last=-1;i<=k;++i)
        {
            int now=Cnt();
            ans+=now;
            cout<<now<<'\n';
            if(last==now)
            {
                ans+=(k-i)*now;
                break;
            }
            last=now;
        }
        cout<<ans<<'\n';
        // cout<<a<<' '<<b<<'\n';

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
