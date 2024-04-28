#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void solve()
    {
        int n;cin>>n;++n;
        vector<int>A(n+1);
        vector<int>lim(n+1);
        for(int i=1;i<n;++i)cin>>A[i];
        int m;cin>>m;
        for(int i=1;i<=m;++i)
        {
            int l,r;cin>>l>>r;
            lim[r+1]=max(lim[r+1],l);
        }
        vector<int>Q(n+1);
        vector<ll>dp(n+1);
        int head=0,tail=0;
        dp[0]=0;
        Q[tail++]=0;
        int now=0;
        for(int i=1;i<=n;++i)
        {
            now=max(now,lim[i]);
            while(head<tail and Q[head]<now)++head;
            dp[i]=dp[Q[head]]+A[i];
            while(head<tail and dp[Q[tail-1]]>dp[i])--tail;
            Q[tail++]=i;
        }
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
