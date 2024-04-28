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
    int ans[N][N];
    int check(int x,int y)
    {
        int res=0;
        if(x>1)++res;
        if(x<n)++res;
        if(y>1)++res;
        if(y<m)++res;
        return res&1;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>s[i]+1;
        int cnt=0;
        cout<<"1\n";
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=m;++j)
            {
                int t=check(i,j)&1;
                int p=s[i][j]=='B';
                cout<<2+(t^p);
            }
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
