#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=2e3+5;
    const int mod=1e9+7;
    char s[N][N];
    bool check(int x,int y)
    {
        if(x>1)if(s[x-1][y]!=s[x][y])return 0;
        if(x<n)if(s[x+1][y]!=s[x][y])return 0;
        if(y>1)if(s[x][y-1]!=s[x][y])return 0;
        if(y<m)if(s[x][y+1]!=s[x][y])return 0;
        return 1;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>s[i]+1;
        int cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cnt+=check(i,j);
        int ans=1,p=2;
        for(;cnt;cnt>>=1)
        {
            if(cnt&1)ans=1ll*ans*p%mod;
            p=1ll*p*p%mod;
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
