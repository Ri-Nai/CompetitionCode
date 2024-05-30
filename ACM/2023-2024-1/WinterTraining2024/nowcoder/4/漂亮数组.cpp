#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),k=rd();
        int S=0;
        map<int,int>pos;
        map<int,int>mark;
        vector<int>dp(n+1);
        mark[0]=1;
        for(int i=1;i<=n;++i)
        {
            S=(S+rd())%k;
            dp[i]=dp[i-1];
            if(mark[S])dp[i]=max(dp[pos[S]]+1,dp[i]);
            mark[S]=1;
            pos[S]=i;
        }
        cout<<dp[n]<<'\n';
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
