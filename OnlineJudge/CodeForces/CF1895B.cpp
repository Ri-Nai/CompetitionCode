#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=205;
    int A[N];
    void solve()
    {
        int n;
        cin>>n;
        n<<=1;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        sort(A+1,A+n+1);
        cout<<A[n/2]-A[1]+A[n]-A[n/2+1]<<'\n';
        for(int i=1;i<=n/2;++i)
            cout<<A[i]<<' '<<A[i+n/2]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
