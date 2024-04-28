#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=505,mod=998244353;
    int n,m,p,q,A[N][N];
    vector<int>ans[2][N];
    void Add(int x,int y,int p,int q)
    {
        for(int i=0;i<x+y;++i)
            ans[x&1][y][i+!A[x][y]]=(ans[x&1][y][i+!A[x][y]]+ans[p&1][q][i])%mod;
    }
    void solve()
    {
        cin>>n>>m>>p>>q;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>A[i][j];
            }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                ans[i&1][j].assign(i+j+1,0);
            if(i==1)ans[1][1][!A[1][1]]=1;
            for(int j=1;j<=m;++j)
            {
                if(i>1)Add(i,j,i-1,j);
                if(j>1)Add(i,j,i,j-1);
            }
        }
        ll res=0;
        for(int i=p;i<=n+m-1-q;++i)
            res=(res+ans[n&1][m][i])%mod;
        cout<<res<<'\n';
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
