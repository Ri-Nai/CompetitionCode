#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e6+5;
    int a,b,c,n,m;
    char p[30],s[M];
    int id[128];
    vector<int>A[30];
    ll dp[M];
    void solve()
    {
        cin>>a>>b>>c;
        cin>>p+1;m=strlen(p+1);
        cin>>s+1;n=strlen(s+1);
        for(int i=1;i<=m;++i)id[p[i]]=i;
        for(int i=1;i<=n;++i)
            A[id[s[i]]].push_back(i);
        for(int i=1;i<=m;++i)
        {
            dp[0]=c*2+b;
            for(int j=1;j<A[i].size();++j)
                dp[j]=dp[j-1]+b+min(c*2,a*(A[i][j]-A[i][j-1]-1));
            cout<<dp[A[i].size()-1]<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T::solve();

}
