#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,m,p;
    int A[N],B[N];
    void solve()
    {
        cin>>n>>p;
        for(int i=1;i<=n;++i)cin>>A[i];
        cin>>m>>p;
        for(int i=1;i<=m;++i)cin>>B[i];
        int ans=0;
        for(int d=1;d>=0 and d<=2e9;d<<=1)
        {
            map<int,int>mp;
            for(int i=1;i<=n;++i)ans=max(ans,++mp[d==1?A[i]:A[i]%d]);
            for(int i=1;i<=m;++i)ans=max(ans,++mp[d==1?B[i]:(B[i]+(d>>1))%d]);
        }
        cout<<ans<<'\n';
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
