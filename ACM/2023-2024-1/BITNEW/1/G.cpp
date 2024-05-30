#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=305;
    ll A[M][M],B[M][M],C[M][M];
    void solve()
    {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>A[i][j];
        for(int i=1;i<=m;++i)
            for(int j=1;j<=k;++j)
                cin>>B[i][j];
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=k;++j)
            {
                C[i][j]=0;
                for(int t=1;t<=m;++t)
                    C[i][j]+=A[i][t]*B[t][j];
                cout<<C[i][j]<<' ';
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
