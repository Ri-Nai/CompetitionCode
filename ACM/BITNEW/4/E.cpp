#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',vonxt()
// namespace T
// {
//     const int N=5e3+5;
//     int n,A[N];
//     int dp[N][2],nxt[N][2],pre[N][2];
//     void solve()
//     {
//         cin>>n;
//         for(int i=1;i<=n;++i)
//             cin>>A[i];
//         int ans=0;
//         // A[n+1]=1e9+5;
//         for(int i=1;i<=n;++i)
//         {
//             dp[i][0]=1;
//             for(int j=i-1;j!=0;--j)
//             {

//                 for(int p=0;p<2;++p)
//                     if(A[i]>A[j])
//                     {
//                         int t=nxt[j][p];
//                         if(!t)continue;
//                         if(dp[j][p]+1>dp[t][p^1])
//                         {
//                             // cout<<j<<' '<<t<<' '<<i<<' '<<p<<'\n';
//                             // cout<<dp[j][p]<<'\n';
//                             // cout<<pre[j][p]<<'\n';
//                             dp[t][p^1]=dp[j][p]+1,pre[i][p]=t;
//                         }
//                         else if(dp[j][p]+1==dp[t][p^1] and (!pre[i][p] or A[pre[i][p]]>A[t]))pre[i][p]=t;
//                     }
//             }
//             for(int j=1;j<i;++j)
//                 for(int p=0;p<2;++p)
//                     if(A[i]>A[pre[j][p]] and (!nxt[j][p] or A[i]<A[nxt[j][p]]))
//                         {
//                             int &o=nxt[j][p];
//                             int &k=pre[i][p];
//                             o=i;
//                             if(!k)k=nxt[j][p];
//                             else if(dp[k][p]<dp[o][p] or dp[k][p]==dp[o][p] and A[o]<A[k])k=o;
//                         }
//             // if(i>=4)
//             // {cout<<"AAAAAAAAAAA\n";
//             // cout<<i<<'\n';
//             // for(int i=1;i<=n;++i)
//             // {
//             //     cout<<i<<":\n";
//             //     for(int j=0;j<=1;++j)
//             //         cout<<dp[i][j]<<' '<<nxt[i][j]<<' '<<pre[i][j]<<'\n';
//             // }
//             // }
//             // cout<<"AAAAAAAAAAAAAAAAA\n";
//             // for(int i=1;i<=n;++i)
//             // cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
//         }
//         for(int i=1;i<=n;++i)
//         {
//             // cout<<nxt[i][0]<<' '<<nxt[i][1]<<'\n';
//             // cout<<dp[i][0]<<' '<<dp[i][1]<<'\n',
//             ans=max(ans,max(dp[i][0]+!!nxt[i][0],dp[i][1]+!!nxt[i][1]));
//         }
//         cout<<ans<<'\n';
//     }
// }
namespace P
{
    const int M=5005;
    int n,A[M],dp[M][M];//表示以i为结尾 以j为倒数第二位
    inline void Max(int &a,int b)
    {
        if(b>a)a=b;
    }
    void Solve()
    {
        cin>>n;
        int ans=1;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=0;i<=n;++i)dp[1][i]=1;
        for(int i=2;i<=n;++i)
        {
            dp[i][0]=1;
            for(int j=1;j<i;++j)
                Max(dp[i][A[j]],1+dp[j][A[i]-1]);
            for(int j=1;j<=n;++j)
                Max(dp[i][j],dp[i][j-1]);
            Max(ans,dp[i][n]);
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int a;
    cout<<a;
    // int t;cin>>t;while(t--)
    // int a=1;
    // cout<<-a++;
    // T::solve();
    P::Solve();
}
