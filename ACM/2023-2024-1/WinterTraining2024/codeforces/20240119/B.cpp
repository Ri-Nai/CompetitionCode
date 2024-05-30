#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n;
    int L[N],R[N],A[N];
    int dp[N];
    int mx[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)dp[i]=0,mx[i]=-1e9;
        //dp[i]=dp[j-1]+i-j+1;找到所有的点
        for(int i=1;i<=n;++i)
        {
            dp[i]=dp[i-1];
            if(mx[A[i]]!=-1e9)
                dp[i]=max(dp[i],mx[A[i]]+i+1);
            mx[A[i]]=max(mx[A[i]],dp[i-1]-i);
            // cout<<mx[A[i]]<<' ';
        }
        // cout<<'\n';
        cout<<dp[n]<<'\n';
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
//123213
/*

( )    )
    (       )
         (      )
*/
