#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n,m,k;
    int A[55],B[55];
    void solve()
    {
        cin>>n>>m>>k;
        for(int i=1,x;i<=n;++i)cin>>A[i];
        for(int i=1,x;i<=m;++i)cin>>B[i];
        int t=50+(k&1);
        for(int i=1;i<=t;++i)
        {
            int p;
            int k1=1,k2=1;
            if(i&1)p=1;else p=-1;
            for(int j=1;j<=n;++j)
                if(p*A[k1]>p*A[j])k1=j;
            for(int j=1;j<=m;++j)
                if(p*B[k2]<p*B[j])k2=j;
            if(A[k1]*p<B[k2]*p)swap(A[k1],B[k2]);
        }
        ll sum=0;
        for(int i=1;i<=n;++i)sum+=A[i];
        cout<<sum<<'\n';

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
