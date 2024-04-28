#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int s[2][3];
    void solve()
    {
        for(int i=0;i<2;++i)
            for(int j=0;j<3;++j)
                cin>>s[i][j];
        ll ans=0;
        for(int i=0;i<3;++i)
        {
            int t=min(s[0][i],s[1][(i+1)%3]);
            s[0][i]-=t;
            s[1][(i+1)%3]-=t;
            ans+=t;
        }
        for(int i=0;i<3;++i)
        {
            int t=min(s[0][i],s[1][i]);
            s[0][i]-=t;
            s[1][i]-=t;
        }
        for(int i=0;i<3;++i)
        {
            int t=min(s[0][i],s[1][(i+2)%3]);
            s[0][i]-=t;
            s[1][(i+2)%3]-=t;
            ans-=t;
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
