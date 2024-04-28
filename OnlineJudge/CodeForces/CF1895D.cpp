#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=2e5+4;
    int n;
    int A[N];
    void solve()
    {
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        for(int i=1;i<=n;++i)
            sum^=A[i];
        for(int i=1;i<=n;++i)
        {

        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
