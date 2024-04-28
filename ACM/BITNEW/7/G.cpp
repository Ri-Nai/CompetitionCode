#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=505;
    int n,m;
    double dp[N][N];
    void solve()
    {
        cin>>m>>n;
        double ans=0;
        memset(dp,0,sizeof dp);
        for(int i=1;i<=m;++i)
        {
            for(int j=n;j>=0;--j)
            {
                for(int k=j;k>=0;--k)
                    dp[i][j-k]=max(dp[i][j-k],dp[i-1][j]+1.*k/j);
                ans=max(ans,dp[i][j]);
            }
        }
        // cout<<dp[n][0]<<'\n';
        printf("%.6f\n",ans);
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
