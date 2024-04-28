#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=2e5+5;
    int n,q,A[M];
    int nxt[M][32];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=0;i<32;++i)
        {
            int now=1<<i;
            for(int j=1;j<=n;++j)
            {
                int k=j;
                if(!(A[j]&now)){nxt[j][i]=-1;continue;}
                while(k+1<=n and A[k+1]&now)++k;
                for(int p=j;p<=k;++p)nxt[p][i]=k;
                j=k;
            }
        }
        cin>>q;
        while(q--)
        {
            int l,k;
            cin>>l>>k;
            int ans=-1;
            int mn=1e9+5;
            for(int i=31;i>=0;--i)
            {
                int t=1<<i;
                if(t&k)
                    mn=min(mn,nxt[l][i]);
                else
                    ans=max(min(mn,nxt[l][i]),ans);
            }
            ans=max(ans,mn);
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
