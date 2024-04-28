#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int A[N],n;
    int L[N],R[N];
    bool check(int a,int d)
    {
        if(a==1 or a==n)return 1;
        return abs(A[a+d]-A[a])<abs(A[a-d]-A[a]);
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        L[1]=0;
        R[n]=0;
        for(int i=2;i<=n;++i)
        {
            if(check(i-1,1))L[i]=L[i-1]+1;
            else L[i]=L[i-1]+A[i]-A[i-1];
        }
        for(int i=n-1;i>=1;--i)
        {
            if(check(i+1,-1))R[i]=R[i+1]+1;
            else R[i]=R[i+1]+A[i+1]-A[i];
        }
        // for(int i=1;i<=n;++i)
        {
            // cout<<L[i]<<' '<<R[i]<<'\n';
            // cout<<check(i,1)<<' '<<check(i,-1)<<'\n';
        }

        int m;
        cin>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            if(y>x)cout<<L[y]-L[x]<<'\n';
            else cout<<R[y]-R[x]<<'\n';
        }
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
