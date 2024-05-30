#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+4;
    struct Pass
    {
        int val,t;
        void input()
        {
            cin>>t>>val;
        }
        bool operator <(const Pass &_)const
        {
            return t<_.t;
        }
    }P[N];
    int n;
    int dp[N];
    void Solve()
    {
        for(int i=1;i<=n;++i)P[i].input();
        sort(P+1,P+n+1);
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for(int i=1;i<=n;++i)
            for(int j=0;j<i;++j)
            {
                int mx=0;
                //线段树 ST表(不会敲)
                for(int k=j+1;k<=i;++k)
                    mx=max(P[k].val,mx);
                dp[i]=min(dp[i],max(P[i].t,dp[j])+mx*2);
            }
        cout<<dp[n]<<'\n';
    }
    void solve()
    {
        while(cin>>n)Solve();
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
/*
首先相信这个是可做的
然后就是
如果说
怎么贪呢怎么贪呢
首先排除奇怪的数据结构(?
dp[i]的话
以i为结尾的回来的时间吧
是否可以考虑啥单调队列优化???
如果
*/
