#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return printf(X),putchar('\n'),void()
bool Nai;
namespace T
{
    const int N=5e5+5;
    int n;
    int A[N],fa[N],sz[N];
    int rd()
    {
        int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
        while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
        return f?-t:t;
    }
    void solve()
    {
        n=rd();
        for(int i=1;i<=n;++i)
            A[fa[i]=i]=rd(),sz[i]=1;
        for(int i=2;i<=n;++i)
            if(A[i]<A[fa[i-1]])
                fa[i]=fa[i-1],++sz[fa[i-1]];
        vector<int>W;
        bitset<N/2>dp;
        dp[0]=1;
        for(int i=1;i<=n;++i)
            if(fa[i]==i)W.push_back(sz[i]);
        if(W.size()>n/2)End("Yes");
        for(int x:W)
        {
            dp|=dp<<x;
            if(dp[n>>1])End("Yes");
        }
        End("No");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
