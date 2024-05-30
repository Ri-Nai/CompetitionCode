#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e3+5;
    int n;
    int A[N],P[N];
    int dp[N][N],ans[N];
    void solve()
    {
        cin>>n;
        memset(ans,0,sizeof ans);
        int now=1;
        for(int i=1;i<=n;++i)P[i]=n+1;
        for(int i=1;i<=n;++i)
        {
            cin>>A[i];
            while(A[i]>=now)P[now++]=i;
        }
        ans[0]=1;
        int res=0;
        for(int i=1;i<=n;++i)
            for(int j=P[i];j<=n;++j)
                ans[j]+=ans[j-1];
        cout<<ans[n]<<'\n';
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
