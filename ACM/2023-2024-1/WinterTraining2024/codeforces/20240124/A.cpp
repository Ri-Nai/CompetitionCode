#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,m,x;
    vector<int>A[N];
    int cnt[N<<3];
    void solve()
    {
        cin>>n>>m>>x;
        if(n>m)
        {
            for(int i=0;i<m;++i)A[i].resize(n);
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    cin>>A[j][i];
            swap(n,m);
        }
        else for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                int y;cin>>y;
                A[i].push_back(y);
            }
        ll ans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
            {
                for(int k=0;k<m;++k)
                {
                    ans+=cnt[A[i][k]^A[j][k]^x];
                    ++cnt[A[i][k]^A[j][k]];
                }
                for(int k=0;k<m;++k)
                    --cnt[A[i][k]^A[j][k]];
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
