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
    const int mod=998244353;
    void Add(int &x,int y)
    {
        x+=y;
        if(x>mod)x-=mod;
    }
    void solve()
    {
        int n=rd();
        vector<int>E;
        for(int i=1;i<=n;++i)E.push_back(rd());
        sort(E.begin(),E.end());
        vector<int>cnt(5006);
        cnt[0]=1;
        int ans=0;
        for(int x:E)
        {
            for(int j=5000;j>=0;--j)
            {
                if(j+x<=5000)Add(cnt[j+x],cnt[j]);
                if(j<=x)Add(ans,1ll*cnt[j]*x%mod);
                else Add(ans,1ll*cnt[j]*((j+x+1)/2)%mod);
            }
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
