#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),limit=rd();
        ll ans=1ll*(limit+1)*(limit+2)/2;
        vector<int>cnt(2);
        for(int i=1;i<=n;++i)
        {
            int x=rd();
            ++cnt[x&1];
            ans-=x/2+1;
            ans-=limit-x;
        }
        ans+=1ll*cnt[0]*(cnt[0]-1)/2;
        ans+=1ll*cnt[1]*(cnt[1]-1)/2;
        cout<<ans<<'\n';
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
