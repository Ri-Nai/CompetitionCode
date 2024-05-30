#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=105;
    int ans[N],n,A[N],res;
    bool mark[N];
    void check()
    {
        int mx=0,mn=1e9;
        for(int i=1;i<=n;++i)
        {
            mx=max(mx,ans[i]);
            mn=min(mn,ans[i]);
            if(mx-mn!=A[i])return ;
        }
        ++res;
    }
    void dfs(int x)
    {
        if(x==n+1)return check();
        for(int i=1;i<=n;++i)
            if(!mark[i])
            {
                mark[i]=1;
                ans[x]=i;
                dfs(x+1);
                mark[i]=0;
            }
    }
    void solve()
    {
        cin>>n;
        res=0;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        dfs(1);
        cout<<res<<'\n';
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
