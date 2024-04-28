#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=2e5+5;
    char s[M];
    int n,k,q,L[M],R[M];
    int is[M],dif[M];
    void solve()
    {
        cin>>n>>k>>s+1;
        for(int i=1;i<=k;++i)cin>>L[i];
        for(int i=1;i<=k;++i)cin>>R[i];
        for(int i=1;i<=k;++i)
            for(int j=L[i];j<=R[i];++j)
                is[j]=i;
        for(int i=1;i<=n;++i)dif[i]=0;
        cin>>q;
        while(q--)
        {
            int x;cin>>x;
            int l=min(L[is[x]]+R[is[x]]-x,x);
            int r=max(L[is[x]]+R[is[x]]-x,x);
            dif[l]^=1;dif[r+1]^=1;
        }
        int now=0;
        for(int i=1;i<=n;++i)
        {
            now^=dif[i];
            int t=i;
            if(now)
                t=L[is[t]]+R[is[t]]-t;
            cout<<s[t];
        }
        cout<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
